/*
Compilers Assignment 1
LANGUAGE NAME: TReK
Group No. 10 (G10)

Members:
1. Kshitij Verma		2017B1A71145H
2. Keshav Beriwal		2017B4A71301H
3. Thejas Sasikumar		2017B4A70614H
4. Rohan Maheshwari		2017B4A70965H

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAlphabet(char c){
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return true;
	return false;
}

bool isNum(char c){
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

/*
isDelimiter(): Checks whether the passed character is a delimiter or not
Parameters:	character c
Returns:	if c is a delimiter true; otherwise false 
*/
bool isDelimiter(char c){
	if(c == ' ' || c == '\n' || c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '>' || c == '<')
		return true;
	else if(c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
		return true;
	return false;
}
/*
printDelimiter(): Prints the passed delimiter in proper format
Parameters:	character c
Returns:	if c is a delimiter true; otherwise false 
*/
bool printDelimiter(char c){
	if(c == '+')
		printf("%-50s","TK_PLUS_OPERATOR");
	else if(c == '-')
		printf("%-50s","TK_MINUS_OPERATOR");
	else if(c == '*')
		printf("%-50s","TK_MUL_OPERATOR");
	else if(c == '/')
		printf("%-50s","TK_DIV_OPERATOR");
	else if(c == '=')
		printf("%-50s","TK_ASSIGNMENT_OPERATOR");
	else if(c == '>')
		printf("%-50s","TK_GT_OPERATOR");
	else if(c == '<')
		printf("%-50s","TK_LT_OPERATOR");
	else if(c == ',')
		printf("%-50s","TK_COMMA_OPERATOR");
	else if(c == ';')
		printf("%-50s","TK_SEMICOL_OPERATOR");
	else if(c == '(')
		printf("%-50s","TK_LPAREN_OPERATOR");
	else if(c == ')')
		printf("%-50s","TK_RPAREN_OPERATOR");
	else if(c == '[')
		printf("%-50s","TK_LSQUAREBRACKET_OPERATOR");
	else if(c == ']')
		printf("%-50s","TK_RSQUAREBRACKET_OPERATOR");
	else if(c == '{')
		printf("%-50s","TK_LCURLYBRACKET_OPERATOR");
	else if(c == '}')
		printf("%-50s","TK_RCURLYBRACKET_OPERATOR");
	else
		return false;
	printf(", string %-40c",c);
	return true;
	
}

/*
isCmpOperator(): Checks whether the 2 passed character constitute a comparison operator or not
Parameters:	character first, character c
Returns:	if c+first is either of {==,<=,>=} true; otherwise false 
*/
bool isCmpOperator(char first, char c){
	if(c == '='){
		if(first == '<')
			printf("%-50s","TK_LTEQ_OPERATOR");
		else if(first == '>')
			printf("%-50s","TK_GTEQ_OPERATOR");
		else if(first == '=')
			printf("%-50s","TK_EQUAL_OPERATOR");
	}
	else
		return false;
	printf(", string %c%-39c",first,c);
	return true;
}

/*
isKeyword(): checks whether the passed string is a keyword(prespecified) or not
Parameters:	character pointer str
Returns:	if str is a keyword true; otherwise false
*/
bool isKeyword(char* str){
	if(!strcmp(str,"main"))
		printf("%-50s","TK_MAIN_KEYWORD");
	else if(!strcmp(str,"void"))
		printf("%-50s","TK_VOID_KEYWORD");
	else if(!strcmp(str,"int"))
		printf("%-50s","TK_INT_KEYWORD");
	else if(!strcmp(str,"float"))
		printf("%-50s","TK_FLOAT_KEYWORD");
	else if(!strcmp(str,"string"))
		printf("%-50s","TK_STRING_KEYWORD");
	else if(!strcmp(str,"input"))
		printf("%-50s","TK_INPUT_KEYWORD");
	else if(!strcmp(str,"write"))
		printf("%-50s","TK_WRITE_KEYWORD");
	else if(!strcmp(str,"for"))
		printf("%-50s","TK_FOR_KEYWORD");
	else if(!strcmp(str,"if"))
		printf("%-50s","TK_IF_KEYWORD");
	else if(!strcmp(str,"else"))
		printf("%-50s","TK_ELSE_KEYWORD");
	else if(!strcmp(str,"return"))
		printf("%-50s","TK_RETURN_KEYWORD");
	else
		return false;
	printf(", string %-40s",str);
	return true;
}

/*
isInteger(): checks whether the passed string is an integer literal or not
Parameters:	character pointer str
Returns:	if str is a integer literal true; otherwise false
*/
bool isInteger(char *str){
	int i, len = strlen(str);

	if(len==0)
		return false;
	for(i = 0; i < len; ++i){
		int val = str[i]; //ASCII 0-9 is 48-57
		if(val<48 || val>57) //NaN
			return false;
	}
	if(str[0]!='0'){
		printf("%-50s","TK_INTEGER_LITERAL");
		printf(", string %-40s",str);
	}
	return true;
}

/*
isFloat(): checks whether the passed string is an float literal or not
Parameters:	character pointer str
Returns:	if str is a float literal true; otherwise false
*/
bool isFloat(char *str){
	int i, len = strlen(str);
	bool hasDecimal = false;

	if(len == 0)
		return false;

	for(i=0; i<len; i++){
		int val = str[i]; //ASCII 0-9 is 48-57
		if(str[i] == '.')
			if(!hasDecimal)
				hasDecimal = true;
			else
				return false;
		else if(val<48 || val>57) //NaN
			return false;
		
	}
	if(hasDecimal){
		printf("%-50s","TK_FLOAT_LITERAL");
		printf(", string %-40s",str);
	}
	return (hasDecimal);
}

/*
isIdentifier(): checks whether the passed string is an identifier(corresponding to the regex) or not
Parameters:	character pointer str
Returns:	if str is an identifier true; otherwise false
*/
bool isIdentifier(char *str){
	int i, len = strlen(str);
	if(isAlphabet(str[0])){ // first char is alphabet
		for(i = 1; i < len; i++){
			if(!(isAlphabet(str[i]) || str[i] == '\\' || str[i] == '.' || isNum(str[i])))
				return false; //if none of the above conditions match, it is not IDENT
		}
	}
	else{
		return false;
	}
	printf("%-50s","TK_IDENT");
	printf(", string %-40s",str);
	return true;
}

/*
isFloat(): checks whether the passed string is an string literal(enclosed in double quotes) or not
Parameters:	character pointer str
Returns:	if str is a string literal true; otherwise false
*/
bool isStringLiteral(char *str){
	int i, len = strlen(str);
	if(str[0] == '\"'){
		return true;
	}
	return false;
}

/*
isComment(): checks whether the passed string is an comment(begins with #) or not
Parameters:	character pointer str
Returns:	if str is a comment true; otherwise false
*/
bool isComment(char *str){
	if(str[0] == '#'){
		return true;
	}
	return false;
}

/*
subString(): Generates substring from the passed string from left to right position
Parameters:	
	character pointer str, 
	integer left(start point of the substring)
	integer right(ending point of the substring)
Returns:
	character pointer subStr(the generated substring)
*/
char* subString(char* str, int left, int right) 
{ 
	int i; 
	char* subStr = (char*)malloc(sizeof(char) * (right - left + 2)); 

  
	for (i = left; i <= right; i++) 
		subStr[i - left] = str[i]; 
	subStr[right - left + 1] = '\0'; 
	return (subStr); 
} 

/*
parse(): main parsing functions, reads the input token by token and determines category of the token
Parameters:
	character pointer str (input line)
	integer line (line number)
*/
void parse(char *str, int line){
	int left = 0, right = 0;
	int len = strlen(str);

	while(right <= len && left <= right){
		if(isDelimiter(str[right]) == false){
			right++;
		}
		if (isDelimiter(str[right]) == true && left == right){
			int check = 1;
			if(str[right] == '<' || str[right] == '>' || str[right] == '='){
				char first = str[right];
				if(right < len && isCmpOperator(first,str[right+1]) == true){
					printf(", line number %d\n",line);
					right++;
					check = 0;
				}
			}
			if(check && printDelimiter(str[right]))
					printf(", line number %d\n",line);
			
			right++;
			left = right;
		}
		else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)){
			char* subStr = subString(str, left, right - 1);
			// printf("%-50s","\nExtracted substring is %s\n",subStr);

			int println=0;//whether to print line no or not


			if (isKeyword(subStr) == true){
				println=1;
			} 

			else if (isInteger(subStr) == true){
				if(subStr[0]=='0'){
					printf("%-50s","TK_INT_LITERAL");
					printf(", string %-40s","0");
					printf(", line number %d\n",line);
					if(strlen(subStr) > 1){
						printf("%-50s","TK_INT_LITERAL");
						printf(", string %-40s",subString(subStr,left+1,right-1));
						println=1;
					}
				}
				else{
					println = 1;
				}
			}

			else if (isFloat(subStr) == true){
				println=1;
			}

			else if (isIdentifier(subStr) == true){
				println=1;
			}

			else if(isStringLiteral(subStr) == true){
				int i = left+1;
				while(i <= len && str[i]!='\"'){
					i++;
				}
				if(i == len+1){
					printf("%-50s","ERROR");
					printf(", string %-40s",subStr);
				}
				else{
					printf("%-50s","TK_STRING_LITERAL");
					printf(", string %-40s",subString(str,left,i));
				}
				right = i+1;
				println=1;
			}
			else if(isComment(subStr) == true){
				//printf("%-50s","COMMENT");
				//printf(", string %-40s",subString(str,left,len-2));
				//printf(", line number %d\n",line);
				break; //whole line is a comment at this point
			}

			else if(strlen(subStr) > 0 && subStr[0]!=' ' && subStr[0]!='\t'){
				//resolving errors like 4abc & 5.12abc
				int i = 0, tleft = left ,extra=0;
				int newlen = right-left;
				bool hasDecimal = false;
				while(i<newlen){
					if(isNum(subStr[i]) || (subStr[i] == '.') ){
						while(i < newlen && (isNum(subStr[i])) || (subStr[i] == '.' && !(hasDecimal)) ){
							if(subStr[i] == '.'){
								hasDecimal = true;
							}
							i++;
						}	
						if(hasDecimal){//float
							if(i-1-extra != 0){
								printf("%-50s","TK_FLOAT_LITERAL");
								printf(", string %-40s",subString(str,left,left + i-1-extra));
								hasDecimal = false;
							}
							else{
								printf("%-50s","ERROR");
								printf(", string %-40s",subString(str,left,left));
							}
							
						}
						else{//int
							printf("%-50s","TK_INT_LITERAL");
							printf(", string %-40s",subString(str,left,left + i-1-extra));
						}
						printf(", line number %d\n",line);
					}
					else if(isAlphabet(subStr[i])){
						while(i < newlen && (isAlphabet(subStr[i]) || isNum(subStr[i]) || subStr[i] == '.')){
							i++;
						}
						printf("%-50s","TK_IDENT");
						printf(", string %-40s",subString(str,left,left+i-1-extra));
						printf(", line number %d\n",line);
					}
					else{
						printf("%-50s","ERROR");
						printf(", string %-40s",subString(str,left,left));
						printf(", line number %d\n",line);
						// println=1;
						i++;
					}
					left = tleft + i;
					extra = i;
					// i++;
				}
			}

			if(println){
				printf(", line number %d\n",line);
			}
			println = 0;
			left = right;
		} 
	}
	return;
}

int main(int argc, char *argv[]){
	FILE *fp;
	fp = fopen(argv[1],"r");

	if(fp == NULL){
		printf("Supplied file failed to open.\n");
		return 0;
	}

	char buff[200];
	int line = 1;
	while(fgets (buff, 200, fp)!=NULL){  
		// printf("%-50s","buffer passed is %s\n\n",buff);
		parse(buff,line);
		line++;
	}

	fclose(fp);
	return 0;
}
