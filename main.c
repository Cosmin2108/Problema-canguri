#include <stdio.h>
#include <stdlib.h>


struct canguri {
 int x, y, salt; /// x si y sunt inceputul si sfarsitul zonei in care se poate deplasa cangurul
 int greutate;

};


void calcul_greutate(struct canguri c[], int  v[], int n, int m)
{
     int i, k;
    for(i=1;i<=m;i++)
    {
        k=0;
        while(c[i].x+k*c[i].salt<=c[i].y)
        {
            v[c[i].x+k*c[i].salt]+=c[i].greutate;
            k++;

        }
    }


}


int main()
{   FILE *f,*g;
    f=fopen("mayonaka.in", "r");
    g=fopen("mayonaka.out", "w");
    int n, m, i;
    int v[100];
    fscanf(f,"%d%d", &n, &m); /// m- nr canguri, n- nr de pozitii pe care pot sari

    struct canguri c[100];

    for(i=1;i<=n;i++)
        v[i]=0;

    for(i=1;i<=m;i++)
        fscanf(f,"%d%d%d%d", &c[i].x, &c[i].y, &c[i].salt,&c[i].greutate);

    calcul_greutate(c,v,n,m);

      for(i=1;i<=n;i++)
            fprintf(g,"%d ", v[i]);

    fclose(f);
    fclose(g);

    return 0;
}
