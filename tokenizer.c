/*
 * tokenizer.c
 * 
 *	By Paulo Garcia and Roel Ronquillo
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */
 
 static char * checkDecimal();
 static char * checkWord();
 static char * checkSpecial();
 static char * parser();
 
struct TokenizerT_ {
	char * input;
	int track;

};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate( char * ts ) {
  TokenizerT *tk = malloc(sizeof(struct TokenizerT_));
	tk->input = ts;
	int x = strlen(ts);
	tk->input[x]='\0';
	tk->track = 0;
  return tk;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk ) {
	free(tk->input);
	free(tk);
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( TokenizerT * tk ) {
  return parser(tk->input, &tk->track);
}

/***********************************************************************
*
*	Keyword Function:
*	Checks for keywords stored in C, in Unix I/O, and in Formatted I/O
*
************************************************************************/
 
void Keyword(char * token){
	if(strcmp(token,"auto")==0){
		printf("auto keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"break")==0){
		printf("break keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"case")==0){
		printf("case keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"char")==0){
		printf("character keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"const")==0){
		printf("constant keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"continue")==0){
		printf("continue keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"default")==0){
		printf("default keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"do")==0){
		printf("do keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"double")==0){
		printf("double keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"else")==0){
		printf("else keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"enum")==0){
		printf("enum keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"extern")==0){
		printf("extern keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"float")==0){
		printf("float keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"fprintf")==0){
		printf("fprintf keyword \"%s\"\n",token);
	}
	if(strcmp(token,"fscanf")==0){
		printf("fscanf keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"for")==0){
		printf("for keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"goto")==0){
		printf("goto keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"if")==0){
		printf("if keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"int")==0){
		printf("integer keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"long")==0){
		printf("long keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"printf")==0){
		printf("printf keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"register")==0){
		printf("register keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"return")==0){
		printf("return keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"short")==0){
		printf("short keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"signed")==0){
		printf("signed keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"sizeof")==0){
		printf("sizeof keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"scanf")==0){
		printf("scanf keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"static")==0){
		printf("static keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"sscanf")==0){
		printf("sscanf keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"sprintf")==0){
		printf("sprintf keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"struct")==0){
		printf("struct keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"switch")==0){
		printf("switch keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"typedef")==0){
		printf("typedef keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"union")==0){
		printf("union keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"unsigned")==0){
		printf("unsigned keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"void")==0){
		printf("void keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"volatile")==0){
		printf("volatile keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"while")==0){
		printf("while keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"NULL")==0){
		printf("NULL keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"open")==0){
		printf("open keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"read")==0){
		printf("NULL keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"Longlseek")==0){
		printf("Longlseek keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"creat")==0){
		printf("creat keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"FILE")==0){
		printf("FILE keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"fopen")==0){
		printf("fopen keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"freopen")==0){
		printf("freopen keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"fread")==0){
		printf("fread keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"fwrite")==0){
		printf("fwrite keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"getc")==0){
		printf("getc keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"putc")==0){
		printf("putc keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"fseek")==0){
		printf("fseek keyword \"%s\"\n",token);
	}
	else
	if(strcmp(token,"write")==0){
		printf("write keyword \"%s\"\n",token);
	}
	else
		printf("word \"%s\"\n",token);
} 

char * checkWord(int * x, char * input){//stores Word and changes pointer integer
  char * token=NULL;
  int BUFF;
  int i = *x;
  while((isalpha(input[i])||isdigit(input[i])||input[i]=='_')&& i<strlen(input)){
    i++;
  }
  BUFF = i - *x;
  token = malloc(sizeof(char) * BUFF);
  strncpy(token, input+*x,BUFF);
  token[BUFF]='\0';
  *x=i;
    Keyword(token);
  return token;
}

/***********************************************************************
*
*	CheckDecimal checks if the stream of numbers start
*	with either a 0 or a different integer. If it starts with a 0
*	then the function checks if its in Hexadecimal form, Octal form or 
*	if it's a regular 0.
*
**************************************************************************/

char * checkDecimal(int *x, char * input){
	
  char * token=NULL;
  int BUFF;
  int i = *x;
  int c1=0, c2 = 0;
  switch(input[i]){
    case'0':
       if((input[i+1]=='x'||input[i+1]=='X')&&
	   (isdigit(input[i+2])||(input[i+2]>='a'&&input[i+2]<='f')||(input[i+2]>='A'&&input[i+2]<='F'))){ //checks for Hexadecimal

       i=i+2;
       while(isdigit(input[i])||(input[i]>='a'&&input[i]<='f')||(input[i]>='A'&&input[i]<='F')){

	i++;
	}
	BUFF = i - *x;
    token = malloc(sizeof(char) * BUFF);
    strncpy(token, input+*x,BUFF);
    token[BUFF]='\0';
    *x=i;
    printf("hex integer \"%s\"\n",token);
	break;
    }
       else						//checks for Octal
	if(isdigit((input[i+1])&&input[i+1]!='0')&&(input[i+1]<='7'&&input[i+1]>='0')){
	  while(input[i]<='7'&&input[i]>='0'){
	    i++;
	  }
	  BUFF = i - *x;
	  token = malloc(sizeof(char) * BUFF);
	  strncpy(token, input+*x,BUFF);
	  token[BUFF]='\0';
	  *x=i;
	  printf("octal integer \"%s\"\n",token);
	break;
	}
	else{

	i++;
	BUFF = i - *x;
	token = malloc(sizeof(char) * BUFF);
	strncpy(token, input+*x,BUFF);
	token[BUFF]='\0';
	*x=i;
	printf("decimal integer \"%s\"\n",token);
	}
      break;
	
    default:					// Checks if decimal or float
      while(isdigit(input[i])&& i<strlen(input)){
      if(input[i+1]=='.'&& isdigit(input[i+2]) && c1==0){

		i=i+2;
		c1++;
	}
      if(input[i+1]=='e'&&input[i+2]=='-'&&isdigit(input[i+3]) && c1==1 && c2==0){
	
		i=i+3;
		c2++;
	}
      i++;
      }
	  BUFF = i - *x;
	  token = malloc(sizeof(char) * BUFF);
	  strncpy(token, input+*x,BUFF);
	  token[BUFF]='\0';
	  *x=i;
	  if(c1!=0)
		printf("float \"%s\"\n",token);
	  else
		printf("decimal integer \"%s\"\n",token);
    break;
  }
  *x=i;
  return token;
}

/**********************************************************************
*
*	Checks for special characters in the C language
*	If the special character can be followed up with another character,
*	this code accounts for those options as well. 
*
***********************************************************************/

char * checkSpecial(int *x, char * input){//stores special char and changes pointer integer

  char * token=NULL;
  int BUFF;
  int i = *x;
  switch (input[i]){
	
	case '-':
		if(input[i+1]=='='){
			printf("minus equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='-'){
			printf("decrement ");
			i++;
			break;
		}
		else
		if(input[i+1]=='>'){
			printf("struct pointer ");
			i++;
			break;
		}
		else
			printf("minus ");
			break;
	
	case '+':
		if(input[i+1]=='='){
			printf("plus equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='+'){
			printf("increment ");
			i++;
			break;
		}
		else
			printf("plus ");
			break;
			
	case '*':
		if(input[i+1]=='='){
			printf("multiply equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='/'){
			printf("end comment block ");
			i++;
			break;
		}
		else
			printf("multiply or pointer ");
			break;
	
	case '/':
		if(input[i+1]=='='){
			printf("divide equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='/'){
			printf("comment line ");
			i++;
			break;
		}
		else
		if(input[i+1]=='*'){
			printf("comment block ");
			i++;
			break;
		}
		else
			printf("divide ");
			break;
	
	case '%':
		if(input[i+1]=='='){
			printf("divide equal ");
			i++;
			break;
		}
		else
			printf("modulus ");
			break;
	
	case '=':
	  if(input[i+1]=='='){
			printf("boolean equal ");
			i++;
			break;
		}
      printf("equals ");
	  break;
	
	case '&':
	  if(input[i+1]=='&'){
			printf("logical and ");
			i++;
			break;
		}
      printf("bitwise and ");
	  break;
	
	case '|':
	  if(input[i+1]=='|'){
			printf("logical or ");
			i++;
			break;
		}
		else
			printf("bitwise or ");
			break;
	
	case '!':
      if(input[i+1]=='='){
		printf("not equal ");
		i++;
		break;
		}
      else
		printf("not ");
		break;
    
	
	case '<':
		if(input[i+1]=='='){
			printf("less than or equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='<'){
			printf("left shift ");
			i++;
			break;
		}
		else
			printf("less than ");
			break;
	
	case '>':
		if(input[i+1]=='='){
			printf("greater than or equal ");
			i++;
			break;
		}
		else
		if(input[i+1]=='>'){
			printf("right shift ");
			i++;
			break;
		}
		else
			printf("greater than ");
			break;
	
	case '\\':
      printf("backslash ");
	  break;
	
	case '(':
      printf("left parenthesis ");
	  break;
	
	case ')':
      printf("right parenthesis ");
	  break;
	  
	case '#':
      printf("hashtag ");
	  break;
	
	case '_':
      printf("underscore ");
	  break;
	
	case '[':
      printf("left brace ");
	  break;
	
	case ']':
      printf("right brace ");
	  break;
	  
	case '{':
      printf("left bracket ");
	  break;

	case '}':
      printf("right bracket ");
	  break;
	  
	case ',':
      printf("comma ");
	  break;
	
	case '^':
      printf("bitwise exclusive or ");
	  break;
	
	case '@':
      printf("at sign ");
	  break;
	  
	case '$':
      printf("dollar sign ");
	  break;
	
	case '.':
      printf("period ");
	  break;
	
	case '\'':
      printf("single quote ");
	  break;
	
	case '~':
      printf("1's comp ");
	  break;
	
	case '`':
      printf("apostraphy ");
	  break;
	
	default:
      printf("unknown character ");
	  break;
  }
  i++;
  BUFF = i - *x;
  token = malloc(sizeof(char) * BUFF);
  strncpy(token, input+*x,BUFF);
  token[BUFF]='\0';
  *x=i;
    printf("\"%s\"\n",token);
  return token;
}

/*******************************************************************
*	Parser Function:
*	based on the track number of the Tokenizer struct, the
*	parser will look at the input char at the given number spot
*	and send it to differnt function parsers depending on
*	what the character in input[i] is. 
*******************************************************************/

char * parser(char * input, int * track){
    int i=*track;
	char * token =NULL;
	
    if(input[i]==' '||input[i]=='\t'||input[i]=='\n'||input[i]=='\v'||input[i]=='\r'||input[i]=='\f'){
      while(input[i]==' '||input[i]=='\t'||input[i]=='\n'||input[i]=='\v'||input[i]=='\r'||input[i]=='\f')
	i++;
	}
	if(input[i]=='\0'||i>strlen(input)){
		*track = i;
	return NULL;
	}
	else
    if(isalpha(input[i])){
		token = checkWord(&i, input);
		*track = i;
		return token;
    }
	else
	if(isdigit(input[i])){
		token = checkDecimal(&i, input);
		*track = i;
		return token;
	}
    else
		token = checkSpecial(&i, input);
		*track = i;
		return token;
}

/***************************************************************
*
*	Main Function: 
*	Creates TokenizerT struct and stores argv[1] inside.
*	Uses a while loop to get next token till the track
*	inside the struct is longer than the char * input inside
*	the struct.
*
************************************************************/	

int main(int argc, char **argv) {

	if (argc != 2 || argc == 1) {
		printf("error: needs one string argument");
		return 0;
	}
	
  int buff = strlen(argv[1]);
  char *input=malloc(sizeof(char)*buff);
  
  strncpy(input,argv[1],buff);
  input[buff]='\0';
  TokenizerT *tk = TKCreate(input);
  
  char * token = NULL;
  while(tk->track<buff){
	token = TKGetNextToken(tk);
	free(token);
  }
  TKDestroy(tk);
  return 0;
}