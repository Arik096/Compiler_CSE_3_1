%{
#include<bits/stdc++.h>
using namespace std;
FILE *f1;
FILE *f2;
int line=1;
struct symbol_table
{
public:
    string variable;
    struct symbol_table *next;
};
long Hash_function(string variable)
{
    long length=0;
    for(long i=0; variable[i]; i++)
    {
        length=(length*(i+1))+variable[i];
    }
    return (length%13);
}
symbol_table *table[13];
void insaert(string variable)
{
    long position=Hash_function(variable);
    if(table[position]==NULL)
    {
        table[position]=new symbol_table();
        table[position]->variable=variable;
        table[position]->next=NULL;
    }
    else
    {
        symbol_table* newNode=new symbol_table();
        newNode->variable=variable;
        symbol_table* nextNode=table[position];
        table[position]=newNode;
        newNode->next=nextNode;
    }
}
long Search(string variable)
{
    long position=Hash_function(variable);
    symbol_table* temp_var=table[position];
    while(temp_var!=NULL)
    {
        if(temp_var->variable.compare(variable)==0)
        {
            return 1;
        }
        temp_var=temp_var->next;
    }
    return 0;
}
void show()
{
    for(long i=0; i<13; i++)
    {
        symbol_table* temp_var=table[i];
        cout<<i<<" -> ";
        while(temp_var!=NULL)
        {
            cout<<"{ "<<temp_var->variable<<" } ";
            temp_var=temp_var->next;
        }
        cout<<endl;
    }
}
void insaert_serach(string variable)
{
long temp_var=Search(variable);
                if(temp_var==0)
                {
                    insaert(variable);
                }

}
void found(string variable)
{
long temp_var=Search(variable);
            if(temp_var==1)
                cout<<"Found"<<endl<<endl;
            else
                cout<<"Not found"<<endl<<endl;
}
%}
%option noyywrap
KEYWORD    [program]|[if]|[end]|[not]|[begin]|[else]|[then]|[do]|[while]|[function]|[procedure]|[integer]|[real]|[var]|[of]|[array]|[write]
WHITESPACE [ \s\t\r\f\v ]
NEWLINE    [\n]
DIGIT      [0-9]
UNDERSCORE [_]
ALPHABET   [a-zA-Z]
NUM        ({DIGIT}+)(\.({DIGIT})+)?(E([+-])?({DIGIT}+)(\.({DIGIT})+)?)?
ID         ({ALPHABET}|{UNDERSCORE})({ALPHABET}|{UNDERSCORE}|{DIGIT})*
RELOP      <|>|<=|>=|=|<>
ADDOP      "+"|"-"|or
MULLOP     "*"|"/"|div|mod|and
ASSIGNOP   :=
BRACKET    "["|"]"
PAREN      "("|")"
DOTDOT     ".."
COMMA      [,]
SEMICOLON  [;]
COLON      [:]
DOT        [.]
%%
{NEWLINE}    { line=line+1;                                                                                            }

{KEYWORD}    { for(int i=0;i<yytext[i];i++) {yytext[i]=toupper(yytext[i]);} fprintf(f1,"< %s >",yytext);             fprintf(f2,"%s found in line %d\n",yytext,line); }

{UNDERSCORE} {                                                              fprintf(f1,"< UNDERSCORE, %s >",yytext);  fprintf(f2,"UNDERSCORE, %s found in line %d\n",yytext,line); }

{ID}         {                                                              fprintf(f1,"< ID, %s >",yytext);          fprintf(f2,"ID, %s found in line %d\n",yytext,line); }

{PAREN}      {                                                              fprintf(f1,"< PAREN, %s >",yytext);       fprintf(f2,"PAREN, %s found in line %d\n",yytext,line); }

{RELOP}      {                                                              fprintf(f1,"< RELOP, %s >",yytext);       fprintf(f2,"RELOP, %s found in line %d\n",yytext,line); }

{ADDOP}      {                                                              fprintf(f1,"< ADDOP, %s >",yytext);       fprintf(f2,"ADDOP, %s found in line %d\n",yytext,line); }

{MULLOP}     {                                                              fprintf(f1,"< MULLOP, %s >",yytext);      fprintf(f2,"MULLOP,%s found in line %d\n",yytext,line); }

{ASSIGNOP}   {                                                              fprintf(f1,"< ASSIGOP, %s >",yytext);     fprintf(f2,"ASSIGNOP, %s found in line %d\n",yytext,line); }

{DOTDOT}     {                                                              fprintf(f1,"< DOTDOT, %s >",yytext);      fprintf(f2,"DOTDOT,%s found in line %d\n",yytext,line); }

{COMMA}      {                                                              fprintf(f1,"< COMMA, %s >",yytext);       fprintf(f2,"COMMA, %s found in line %d\n",yytext,line); }

{SEMICOLON}  {                                                              fprintf(f1,"< SEMICOLON, %s >",yytext);   fprintf(f2,"SEMICOLON, %s found in line %d\n",yytext,line); }

{COLON}      {                                                              fprintf(f1,"< COLON, %s >",yytext);       fprintf(f2,"COLON, %s found in line %d\n",yytext,line); }

{DOT}        {                                                              fprintf(f1,"< DOT, %s >",yytext);         fprintf(f2,"DOT, %s found in line %d\n",yytext,line); }

{NUM}        {                                                              fprintf(f1,"< NUM, %s >",yytext);         fprintf(f2,"NUM, %s found in line %d\n",yytext,line); }

%%
int main()
{
yyin=fopen("input.txt","r");
f1=fopen("Token.txt","w");
f2=fopen("Log.txt","w");
yylex();
return 0;
}
