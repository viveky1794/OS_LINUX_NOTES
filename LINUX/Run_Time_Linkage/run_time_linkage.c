#include<stdio.h>
#include<dlfcn.h>

int main()
{
void *handle;

int (*p)(int ,int);

int x,y,result,choice;

printf("Enter 2 int:\n");
scanf("%d %d",&x,&y);

printf("Enter choice\n");
scanf("%d",&choice);

if(choice  == 1)
{
handle = dlopen("./libDyn.so",RTLD_LAZY);
p = dlsym(handle,"sum");
result = (*p)(x,y);
dlclose(handle);
}
else if(choice == 2)
{
handle = dlopen("./libDyn.so",RTLD_LAZY);
p = dlsym(handle,"mul");
result = (*p)(x,y);
dlclose(handle);
}

}
