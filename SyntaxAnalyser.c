/*  
    NOTE:
	-> This program will read another .c file and give the complete info about the code in that file e.g 
	number of int, floats, char etc variable used
	if there is any error in the brackets
	how many function are used
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
		char l[1000];
		int ln;
}s2;
void file_reading(s2 file[],int* linecount);
void chk(s2 file[],int*intf,int curve, int*prntf ,int*scnf,int*fpts,int*fgts ,int*ffloat, int*fscnf, int*curly, int*straight,int*flot, int*nt, int*chr, int*pts,int*gts, int vod );

main(){
s2 file[1000];
int lc=0;  
char d[901];
file_reading(file, &lc);//in total lines..code is counting extra used lines too...
int i=0,k=0,j=1,m,intf=0,prntf=0,scnf=0,fpts=0,fgts=0,ffloat=0,fscnf=0,curly=0,curve=0,straight=0,flot=0,nt=0,chr=0,pts=0,gts=0,vod=0;
//printf("%d",file[1].ln);
chk(file,&intf,&curve, &prntf ,&scnf,&fpts,&fgts ,&ffloat, &fscnf, &curly, &straight,&flot, &nt, &chr, &pts,&gts, &vod );
printf("\n\n\nBASIC INFORMATION ABOUT THE ABOVE CODE\n=========================================");
printf("\n\tTotal Number Of Lines-->\t\t        %d",lc);
printf("\n\tTotal Built In Functions Used-->\t\t%d",prntf+scnf+fscnf+fgts+fpts);
printf("\n\tTotal Number Of Variables Used-->\t\t%d",chr+flot+nt-intf-ffloat);
printf("\n\nINFORMATION ABOUT FUNCTIONS USED IN THE ABOVE CODE\n=====================================================");
if(vod>0)printf("\n\tTotal Number Of \"void\" Fuctions-->         %d",vod);

if(intf>0)printf("\n\tTotal Number Of \"integer\" Fuctions-->      %d",intf);

if(ffloat>0)printf("\n\tTotal Number Of \"float\" Fuctions-->     %d",ffloat);

if(prntf>0)printf("\n\tTotal Number Of \"printf\" Function-->       %d",prntf);

if(scnf>0)printf("\n\tTotal Number Of \"scanf\" Function-->        %d",scnf);

if(fscnf>0)printf("\n\tTotal Number Of \"fscanf\" Function-->       %d",fscnf);

if(fgts>0)printf("\n\tTotal Number Of \"fgets\" Function-->        %d",fgts);

if(fpts>0)printf("\n\tTotal Number Of \"fputs\" Function--->       %d",fpts);
	
if(pts>0)printf("\n\tTotal Number Of \"puts\" Function-->         %d",pts);

if(gts>0)printf("\n\tTotal Number Of \"gets\" Function-->         %d",gts);

printf("\n\nINFORMATION ABOUT THE BRACKETS USED IN ABOVE CODE\n====================================================");
if(curly>0)printf("\n\t%d Clossing Curly Bracket Is Missing ",curly);//if count = -n that means there are } extra brackets. 
else if(curly<0)printf("\n\t%d Openning Curly Bracket Is Missing",-curly);
else printf("\n\tCurly Brackets Are Perfectly Closed");

if(curve>0)printf("\n\t%d Closing Curve Bracket Is Missing ",curve);//if count = -n that means there are ) extra brackets.
else if(curve<0)printf("\n\t%d Openning Curve Bracket Is Missing",-curve);
else printf("\n\tCurve Brackets Are Perfectly Closed");

if(straight>0)printf("\n\t%d Clossing Long Bracket Is Missing ",straight);//if count = -n that means there are ] extra brackets.
else if(straight<0)printf("\n\t%d Openning Long Bracket Is Missing",-straight);
else printf("\n\tLong Brackets Are Perfectly Closed");

printf("\n\nINFORMATION ABOUT THE VARIABLES USED\n========================================");
if(flot>0)printf("\n\tThe Number Of Floats Type Variables Used Are ---> %d",flot-ffloat);
else printf("\n\tNo Float Type Variables Have Been Used");

if(nt-intf>0)printf("\n\tThe Number Of Integer Type Variables Used Are --> %d",nt-intf);
else printf("\n\tNo Integer Type Variables Have Been Used");

if(chr>0)printf("\n\tThe Number Of Character Type Variables Used Are -->%d",chr);
else printf("\n\tNo Character Type Variables Have Been Used");
}

void file_reading(s2 file[],int* linecount){
	FILE *p;
	p=fopen("Code To Check.c","r");
	int i=0,k=0;
    while(!feof(p)){
		fgets(file[i].l,1000,p);
		if((file[i].l[1]==' '||file[i].l[0]=='\n')||(file[i].l[0]=='/'&&file[i].l[1]=='/'))continue;
		*linecount+=1;
		file[i].ln=strlen(file[i].l);
		for(k=0;k<file[i].ln;k++){
			if(file[i].l[k]=='/'&&file[i].l[k+1]=='/'){
			    file[i].l[k]='\n';
			    file[i].l[k+1]='\0'; 
		    }
	file[i].ln=strlen(file[i].l);
	}printf("%d",i+1);
	printf("-%s",file[i].l);
	i++;
}
//printf("%d- }",i+1);
}
void chk(s2 file[],int*intf,int curve, int*prntf ,int*scnf,int*fpts,int*fgts ,int*ffloat, int*fscnf, int*curly, int*straight,int*flot, int*nt, int*chr, int*pts,int*gts, int vod ){
	int l,i,k,m;
	for(i=0;i<500;i++){
		for(k=0;k<file[i].ln;k++){
/scanf/	if(file[i].l[k]=='s'&&file[i].l[k+1]=='c'&&file[i].l[k+2]=='a'&&file[i].l[k+3]=='n'&&file[i].l[k+4]=='f'&&file[i].l[k+5]=='('){*scnf+=1;}
/printf/	if(file[i].l[k]=='p'&&file[i].l[k+1]=='r'&&file[i].l[k+2]=='i'&&file[i].l[k+3]=='n'&&file[i].l[k+4]=='t'&&file[i].l[k+5]=='f'&&file[i].l[k+6]=='('){*prntf+=1;}
/fscanf/	if(file[i].l[k]=='f'&&file[i].l[k+1]=='s'&&file[i].l[k+2]=='c'&&file[i].l[k+3]=='a'&&file[i].l[k+4]=='n'&&file[i].l[k+5]=='f'&&file[i].l[k+6]=='('){*fscnf+=1;}
/fgets/	if(file[i].l[k]=='f'&&file[i].l[k+1]=='g'&&file[i].l[k+2]=='e'&&file[i].l[k+3]=='t'&&file[i].l[k+4]=='s'&&file[i].l[k+5]=='('){*fgts+=1;}
/fputs/	if(file[i].l[k]=='f'&&file[i].l[k+1]=='p'&&file[i].l[k+2]=='u'&&file[i].l[k+3]=='t'&&file[i].l[k+4]=='s'&&file[i].l[k+5]=='('){*fpts+=1;}	
/gets/	if(file[i].l[k]=='g'&&file[i].l[k+1]=='e'&&file[i].l[k+2]=='t'&&file[i].l[k+3]=='s'&&file[i].l[k+4]=='('){*gts+=1;}
/puts/	if(file[i].l[k]=='p'&&file[i].l[k+1]=='u'&&file[i].l[k+2]=='t'&&file[i].l[k+3]=='s'&&file[i].l[k+4]=='('){*pts+=1;}

	if(file[i].l[k]=='v'&&file[i].l[k+1]=='o'&&file[i].l[k+2]=='i'&&file[i].l[k+3]=='d'&&file[i].l[k+4]==' '){
			for(m=0;m<file[i].ln;m++){
				if(file[i].l[m]=='('){
					*vod+=1;
					break;
				}
			}
		}
		
			if(file[i].l[k]=='f'&&file[i].l[k+1]=='l'&&file[i].l[k+2]=='o'&&file[i].l[k+3]=='a'&&file[i].l[k+4]=='t'&&file[i].l[k+5]==' '){
			for(m=0;m<file[i].ln;m++){
				if(file[i].l[m]=='('){
					*ffloat+=1;
					break;
				}
			}
		}
			if(file[i].l[k]=='{'){*curly++;}
			if(file[i].l[k]=='}'){*curly--;}
			if(file[i].l[k]=='('){*curve++;}
			if(file[i].l[k]==')'){*curve--;}
			if(file[i].l[k]=='['){*straight++;}
			if(file[i].l[k]==']'){*straight--;}
			if(file[i].l[k]=='f'&&file[i].l[k+1]=='l'&&file[i].l[k+2]=='o'&&file[i].l[k+3]=='a'&&file[i].l[k+4]=='t'&&file[i].l[k+5]==' '){
				*flot+=1;
				for(k=k+6;k<=file[i].ln;k++){
                    	if(file[i].l[k]==',')*flot+=1;
				   		if(file[i].l[k]==';')break;
				    	else continue;
				}
			}
			if(file[i].l[k]=='i'&&file[i].l[k+1]=='n'&&file[i].l[k+2]=='t'&&file[i].l[k+3]==' '){
				*nt+=1;
				for(k=k+4;k<=file[i].ln;k++){
                    if(file[i].l[k]==',')*nt+=1;
				    if(file[i].l[k]==';')break;
				    else continue;
				}
			}
			if(file[i].l[k]=='c'&&file[i].l[k+1]=='h'&&file[i].l[k+2]=='a'&&file[i].l[k+3]=='r'&&file[i].l[k+4]==' '){
				*chr+=1;
				for(k=k+5;k<=file[i].ln;k++){
                    if(file[i].l[k]==',')*chr+=1;
				    if(file[i].l[k]==';')break;
				    else continue;
				}
			}
		}
	}
	for(i=0;i<500;i++){
		for(k=0;k<file[i].ln;k++){
			if(file[i].l[k]=='i'&&file[i].l[k+1]=='n'&&file[i].l[k+2]=='t'&&file[i].l[k+3]==' '){
			    for(k=k+4;k<=file[i].ln;k++){
				    if(file[i].l[k]=='('){
					    *intf+=1;
					    break;
			    	}  
		    	}
	    	}
		}
	}
}