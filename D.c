#include<stdio.h>

main()
{
    int z;
    scanf("%d", &z);

    int i;
    for(i=0; i<z; i++)
    {
        double a, l, p;
        scanf("%lf", &a);

        l=0; p=a;
        double s=l, t=s*s*s-s*s+s;
        //printf("%f-%f\n", l, p);

        while(p-l>=0.0000000001)
        {
            //printf("%lf-%lf\n", l, p);
            s=(l+p)/2.0;
            t=s*s*s-s*s+s;

            //if(t==a) {p=s; l=s;}
            if(t<a) l=s;
            else p=s;
        }

        printf("%.10lf %d %d\n", p, (int)p, (int)(p+0.9999999999));
    }
}
