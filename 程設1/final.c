int *max(int *a, int *b)
{
if (*a > *b)
return a;
else
return b;
}
int main()
{
int *p, i, j;
p = max(&i, &j); /* After the call, p points to either i or j. */
printf("%d",p);
return 0;
}
