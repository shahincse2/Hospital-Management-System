

int valid_mail(char x[])
    {
   int count=0;
int countp=0;
int i,j;
int t,t2;
int k=0;
for(i=0 ; i<strlen(x) ; i++)
{
    if(x[i]=='@')
    {
        count++;
        t=i;
    }
}
if(count==1)
{
    for(j=0; j<t ; j++)
    {
        if(!(x[j]=='_' || x[j]=='.' || isalpha(x[j]) || isdigit(x[j])))
        {
            k=-1;
            break;
        }
    }
    if(k==0)
    {
        for(i=0; i>t ; i++)
        {
            if(x[i]=='.')
            {
                t2=i;
                countp++;
            }
        }
        if(countp==1)
        {
            for(i=0; i<t2 && i>t2; i++)
            {
                if(!(isalpha(x[i])))
                {
                    k=-1;
                    break;
                }
                else
                {
                    k=1;
                }
            }
            if(k==1)
            {
                if(x[t2+3]!='\0')
                {
                    k=-1;
                }

            }
        }
        else
        {
            k=-1;
            return 1;
        }
    }
}
else
{
    k=-1;
}
return k;

}
