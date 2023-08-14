#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "functions.h"

#define bx 19	//bx and by are constants that has to be changed manually when the input maze changes.
#define by 10    
#define iq 200	//memory size

char maze[bx][by]; // Maze
int mem[200][2];  // Memory array
int pos[2];        // Current Position

char itchdir;
int s=0;
int deedcount=0;
int deedvalue=0;
int mem_index=0;//for the push function.dont use anywhere else.

int numSteps=0;

FILE *moves;

//Marks position
void MARK(){maze[pos[0]][pos[1]] = 'P';
	fprintf(moves,"%s","MARK\n");
	numSteps++;
}

int PUSH(int s ,int x, int y){
    int i = 0;
    //printf("push: %d %d \n",x,y);
    if(isFull(s) == 1){printf("full\n");}
    else{
        mem[s][0] = x;
        mem[s][1] = y;
        
        s++;
    }
    //printf("push: %d %d \n",mem[s-1][0],mem[s-1][1]);    //if u want to see it, u have to do s-1 because s is added +1 where nothing is present.
    fprintf(moves,"%s","PUSH\n");
    numSteps++;
    return s;
}



//Movement Functions
int MOVE_F(int s){
        pos[0] = pos[0] + 1;
        int value;
        if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
            deedcount+=1;
            value=maze[pos[0]][pos[1]]-'0';
            deedvalue+=value;
        }
        MARK();
        s=PUSH(s,pos[0],pos[1]);
        numSteps++;
        	fprintf(moves,"%s","MOVE_F\n");
        return s;
	
}

int MOVE_B(int s){
        pos[0] = pos[0] - 1;
        int value;
        if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
            deedcount+=1;
            value=maze[pos[0]][pos[1]]-'0';
            deedvalue+=value;
        }
        MARK();
        s=PUSH(s,pos[0],pos[1]);
        numSteps++;
         fprintf(moves,"%s","MOVE_B\n");
        return s;
       
}
int MOVE_R(int s){
    pos[1] = pos[1] + 1;
    int value;
    if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
        deedcount+=1;
        value=maze[pos[0]][pos[1]]-'0';
        deedvalue+=value;
    }
    MARK();
    s=PUSH(s,pos[0],pos[1]);
    numSteps++;
    fprintf(moves,"%s","MOVE_R\n");
    return s;
   
}
int MOVE_L(int s){
    pos[1] = pos[1] - 1;
    int value;
    if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
        deedcount+=1;
        value=maze[pos[0]][pos[1]]-'0';
        deedvalue+=value;
    }
    MARK();
    s=PUSH(s,pos[0],pos[1]);
    numSteps++;
    	fprintf(moves,"%s","MOVE_L\n");
    return s;

}

//Next space cheker for itch
int CWF(int x,int y){
     //keeps checking till it reaches a wall.
    int i=1;
    while ( maze[x+i][y] == ' ' && maze[x+i][y] != 'P' && maze[x+i][y] != '*'|| (maze[x+i][y]>='0' && maze[x+i][y]<='9')) {	
	//the ant considers the numbers as a free space but it doesnt know that there is a number there.
        i++;
    }
    numSteps++;
    i=i-1;    //the last value of i is when the loop terminates.
    	fprintf(moves,"%s","CWF\n");
    return i;
}
int CWB(int x,int y){
     int i=1;
     while (maze[x-i][y] == ' ' && maze[x-i][y] != 'P' && maze[x-i][y] != '*' || (maze[x-i][y]>='0' && maze[x-i][y]<='9')){
         i++;
     }
     numSteps++;
     i=i-1;
     	fprintf(moves,"%s","CWB\n");
     return i;
}
int CWR(int x,int y){
    int i=1;
    while (maze[x][y+i] == ' ' && maze[x][y+i] != 'P' && maze[x][y+i] != '*' || (maze[x][y+i]>='0' && maze[x][y+i]<='9')){
        i++;
    }
    numSteps++;
    i=i-1;
    	fprintf(moves,"%s","CWR\n");
    return i;
}
int CWL(int x,int y){
    int i=1;
    while ( maze[x][y-i] == ' ' && maze[x][y-i] != 'P' && maze[x][y-i] != '*' || (maze[x][y-i]>='0' && maze[x][y-i]<='9')){
        i++;
    }
    numSteps++;
    i=i-1;
    	fprintf(moves,"%s","CWL\n");
    return i;
}

//Memory full and empty checker
int isFull(int s){return (s >= iq)? 1:0;}
int isEmpty(int s){return (s <= 0 )? 1:0;}

//Memory Functions


int POP(int size){
    if(isEmpty(size) == 1){printf("empty\n");}
    else{size=size-2;}
    fprintf(moves,"%s","POP\n");
    numSteps++;
    return size;
}

void PEEK(int size){ pos[0]=mem[size][0]; pos[1]=mem[size][1];
	fprintf(moves,"%s","PEEK\n");
	numSteps++;}

int CLEAR(){s=0; return s;
	fprintf(moves,"%s","CLEAR\n");
	numSteps++;} // (s)ize = 0;


//Itching functions
int BJPI(char dir,int x){
		fprintf(moves,"%s","BJPI\n");
//    int itch = itches(dir);
	int value;
    switch(dir){
        case 'F':
            //printf("%d",atoi("9"));
            pos[0] = pos[0] + x;
            if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
				deedcount+=1;
				value=maze[pos[0]][pos[1]]-'0';
				deedvalue+=value;
			}          
            break;
        case 'B':
            pos[0] = pos[0] - x;
            if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
				deedcount+=1;
				value=maze[pos[0]][pos[1]]-'0';
				deedvalue+=value;
			}
            break;
        case 'L':
            pos[1] = pos[1] - x;
            if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
				deedcount+=1;
				value=maze[pos[0]][pos[1]]-'0';
				deedvalue+=value;
			}
            break;
        case 'R':
            pos[1] = pos[1] + x;
            if(maze[pos[0]][pos[1]]>='0' &&maze[pos[0]][pos[1]]<='9'){
				deedcount+=1;
				value=maze[pos[0]][pos[1]]-'0';
				deedvalue+=value;
			}
            break;
        default:
            break;
    }
    MARK();
    s=PUSH(s,pos[0],pos[1]);
    numSteps++;
    return s;
}

int CJPI(char dir){
		fprintf(moves,"%s","CJPI\n");
    switch(dir){
        case 'F':
            pos[0] = pos[0] + 1;
            break;
        case 'B':
            pos[0] = pos[0] - 1;
            break;
        case 'L':
            pos[1] = pos[1] + 1;
            break;
        case 'R':
            pos[1] = pos[1] - 1;
            break;
    }
    MARK();
	s=PUSH(s,pos[0],pos[1]);
    numSteps++;
    return s;
}

//Goes to last location
void BACKTRACK(int size){
		fprintf(moves,"%s","BACKTRACK\n");
    POP(size);
    numSteps++;
 }

//int teleport_pos[iq][2];
//int teleport_s=0;
//void teleport(){    //magic trick 1
//    pos[0]=teleport_pos[teleport_s-1][0];
//    pos[1]=teleport_pos[teleport_s-1][1];
//    teleport_s--;
//    numSteps++;
//}
//Repetition function for commands
void RP(FILE *brain){
			fprintf(moves,"%s","RP\n");
        int x,y,n,t,i,j,largest=0,spaces=0;
    int f_spaces=0,b_spaces=0,l_spaces=0,r_spaces=0;
    char command[10];
    int n_dir=0;
    
        
    //    s=commandPharse(command,s);
       // if(strcmp(command,"RP")==0){
            fscanf(brain,"%d",&n);
            fscanf(brain,"%d",&t);
            
            for(i=0;i<t;i++){
                //printf("beginning:%d%d ",pos[0],pos[1]);
                f_spaces=0,b_spaces=0,l_spaces=0,r_spaces=0;
                largest=0;
                
                n_dir=0;    //number of directions where there is a free space.
                for(j=0;j<n;j++){
                    fscanf(brain,"%s",command);
                    if(strcmp(command,"CWF") == 0){
                        f_spaces=CWF(pos[0],pos[1]);
                        
                        if(f_spaces>largest){
                            largest=f_spaces;
                            itchdir='F';
                            break;
                        }
                        if(f_spaces>=1){
                            n_dir++;
                        }

                    }
                    
                    else if(strcmp(command,"CWB") == 0){
                        b_spaces=CWB(pos[0],pos[1]);
                        if(b_spaces>largest){
                            largest=b_spaces;
                            itchdir='B';
                        }
                        if(b_spaces>=1){    //atleast one free space in that direction. we can use a magic trick to come back to the position with largest n_dir.
                            n_dir++;    //maybe we can rememeber the positions where there is an opening to go to next row(move forward).
                        };

                    }
                    
                    else if(strcmp(command,"CWL") == 0){
                        l_spaces=CWL(pos[0],pos[1]);
                        if(l_spaces>largest){
                            largest=l_spaces;
                            itchdir='L';
                        }
                        if(l_spaces>=1){
                            n_dir++;
                        }

                    }
                    
                    else if(strcmp(command,"CWR") == 0){
                        r_spaces=CWR(pos[0],pos[1]);
                        if(r_spaces>largest){
                            largest=r_spaces;
                            itchdir='R';
                        }
                        if(r_spaces>=1){
                            n_dir++;
                        }

                    }
                    
                }
                
//                if(n_dir>=2){
//                    teleport_pos[teleport_s][0]=pos[0];
//                    teleport_pos[teleport_s][1]=pos[1];
//                    teleport_s++;
//                }
                
            //    printf("%d%d ",teleport_pos[teleport_s-1][0],teleport_pos[teleport_s-1][1]);
//                printf("%d%d",pos[0],pos[1]);		//seeing at each step.
//                printf(" %d%d%d%d ",f_spaces,b_spaces,l_spaces,r_spaces);
//                printf("%d ",largest);
//                printf("%c ",itchdir);
//                printf("%d",s);
//                printf("\n");
            
                
                switch(itchdir){
                    case 'F':
                        s=MOVE_F(s);
                        //s=BJPI(itchdir,largest);    //try using the moving one step at a time to get the good deeds
                        break;
                    case 'B':
                        //s=MOVE_B(s);
                        s=BJPI(itchdir,largest);
                        break;
                    case 'L':
                        //s=MOVE_L(s);
                        s=BJPI(itchdir,largest);
                        break;
                    case 'R':
                        //s=MOVE_R(s);
                        s=BJPI(itchdir,largest);
                        break;
                    default:
                        MOVE_F;
                        break;
                }
                
                
                //printf("mem:%d,%d\n",mem[s-1][0],mem[s-1][1]);
                //printf("%d , %d \n",mem[mem_index][0],mem[mem_index][1]);
                
//                for(x=0;x<bx;x++){
//                    for(y=0;y<by;y++){
//                        printf("%c",maze[x][y]);
//                    }
//                    printf("\n");
//                }
                
                rewind(brain);
                fscanf(brain,"%s",command);
                fscanf(brain,"%s",command);
                fscanf(brain,"%s",command);
                
                
                //printf("%d,%d\n ",pos[0],pos[1]);
//                while(largest==0){
//                        printf("backtracking\n");
//                        BACKTRACK(s-1);
//                        printf("%d,%d\n",pos[0],pos[1]);
//                        break;
//                    //printf("%d%d ",mem[s-1][0],mem[s-1][1]);
//                    }
                
                //printf("after backtrack:%d%d\n",pos[0],pos[1]);
//                if(pos[0]<bx && pos[1]<by && maze[pos[0]][pos[1]]=='*'){
//                    printf("end:%d%d ",pos[0],pos[1]);
//                    break;
//                }
				if(largest==0){
            		
            		break;
				}
				
            }            
      //  }
}

void Start(){
	  FILE *map , *brain;

    if(((map = (fopen("maze.txt","r"))))== NULL){exit(1);}
    if(((brain = (fopen("intel2.txt","r"))))== NULL){exit(1);}
    if(((moves = (fopen("moves.txt","w"))))== NULL){exit(1);}
    
    char c;
    char command[10];
    int x,y;
    char n_dir;
    
    int i;

    x = 0;
    y = 0;

//    pos[0] = 0;
//    pos[1] = 3;
    
    while((c = fgetc(map)) != EOF){
        if(c == '\n'){
            x++;
            y=0;
        }
        else{
        maze[x][y] = c;	//adding maze to our 2d array.
        y++;
    }
    }
    
    printf("user entered maze:\n");
    for(x=0;x<bx;x++){	//bx and by are constants that has to be changed manually when the input maze changes.
        for(y=0;y<by;y++){
            printf("%c",maze[x][y]);	//displaying the maze.
        }
        printf("\n");
    }
    
    for(i=0;i<y;i++){
    	if(maze[0][i]==' '){	//finding the entry point.
    		pos[0]=0;
    		pos[1]=i;
		}
	}
	
    MARK();
    s=PUSH(s,pos[0],pos[1]);	//adding the entry point to the memory.
	
	fscanf(brain,"%s",command);
	if(strcmp(command,"RP")==0){
    	RP(brain);
	}
	
	printf("\n");
	for(x=0;x<bx;x++){
        for(y=0;y<by;y++){
            fprintf(moves,"%c",maze[x][y]);	//displaying the end maze.
        }
        fprintf(moves,"\n");
    }
    fprintf(moves,"THE END.\n");
	fprintf(moves,"deedcount:%d\ndeedvalue:%d",deedcount,deedvalue);
	fprintf(moves,"\nNumber of steps performed: %d", numSteps); 
}

//int dirs[3][3][2] = {{{3,1},{0,1},{4,1}} , {{3,0},{0,0},{4,0}} , {{3,2},{0,2},{4,2}}}
//char directions[5] = "NBFLR";
//char n[3][3];
//
//void radar(int x, int y){
//    int w,l,f; w = 3; l = w; f = l/2; // length x witdh of searching area and factor
//    int k,p,i; k = 0;p = 0;
//
//    for(i = x - f; i <= x + f; i++){
//        for(u = y - f; u <= y + f; u++){
//            p++;
//            if(maze[i][u]>='0' &&maze[i][u]<='9')){
//                rd1 = directions[dirs[i][u][0]];
//                rd2 = directions[dirs[i][u][1]];
//                break;
//            }
//        }
//        k++;
//        p=0;
//    }
//}


//void skip(int n,FILE *f){
//    int i;
//    for(i=0;i<n;i++){
//        fscanf(f,"%s");
//    }
//}

