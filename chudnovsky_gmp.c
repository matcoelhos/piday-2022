#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>
#include<string.h>
#include<tgmath.h>
#include<gmp.h>

const float logvalue = 3.3219280948873623479;

int main(int argc, char * argv[])
{
	int precision = atoi(argv[1]);
	int num_iterations = ((precision)/14)-1;
	int bits = (int)(precision*logvalue);
	printf("Precision: %d, bits: %d\n",precision, bits);

	mpf_set_default_prec(bits);

	mpf_t sum,pi;
	mpf_t Lq, Mq, Xq, Kq, C;
	mpf_t const1, const2, const3, const4;
	mpf_t q,aux,t1,t2,t3;

	mpf_init(sum);
	mpf_init(Lq);
	mpf_init(Mq);
	mpf_init(Xq);
	mpf_init(Kq);
	mpf_init(C);
	mpf_init(pi);

	mpf_init(const1);
	mpf_init(const2);

	mpf_init(q);
	mpf_init(aux);
	mpf_init(t1);
	mpf_init(t2);
	mpf_init(t3);

	mpf_set_si(C,426880);
	mpf_set_si(aux,10005);
	mpf_sqrt(aux,aux);
	mpf_mul(C,C,aux);

	mpf_set_si(sum,0);
	mpf_set_si(Lq,13591409);
	mpf_set_si(Xq,1);
	mpf_set_si(Mq,1);
	mpf_set_si(Kq,-6);

	mpf_mul(aux,Mq,Lq);
	mpf_div(aux,aux,Xq);
	mpf_add(sum,sum,aux);

	mpf_set_si(const1,545140134);
	mpf_set_si(const2,-262537412640768000);

	int iter = 1;
	mpf_set_si(q,0);
	while(iter <= num_iterations)
	{
		mpf_add_ui(q,q,1);
		mpf_add(Lq,Lq,const1);
		mpf_mul(Xq,Xq,const2);
		mpf_add_ui(Kq,Kq,12);

		mpf_pow_ui(t1,Kq,3);
		mpf_pow_ui(t2,q,3);
		mpf_mul_ui(t3,Kq,16);

		mpf_sub(aux,t1,t3);
		mpf_div(aux,aux,t2);
		mpf_mul(Mq,Mq,aux);

		mpf_mul(aux,Mq,Lq);
		mpf_div(aux,aux,Xq);
		mpf_add(sum,sum,aux);

		printf("Round %d/%d done\r",iter,num_iterations);

		iter++;
	}
	printf("\n");

	mpf_div(pi,C,sum);

	FILE* f;
	f = fopen("solution_c.txt","w");
	gmp_fprintf(f,"%.*Ff\n", precision+1, pi);
	fclose(f);

	mpf_clear(sum);
	mpf_clear(Lq);
	mpf_clear(Mq);
	mpf_clear(Xq);
	mpf_clear(Kq);
	mpf_clear(C);
	mpf_clear(pi);
	mpf_clear(const1);
	mpf_clear(const2);
	mpf_clear(q);
	mpf_clear(aux);
	mpf_clear(t1);
	mpf_clear(t2);
	mpf_clear(t3);
}