void MARK();
int PUSH(int s ,int x, int y);
int MOVE_F(int s);
int MOVE_B(int s);
int MOVE_L(int s);
int MOVE_R(int s);
int CWF(int x,int y);
int CWB(int x,int y);
int CWL(int x,int y);
int CWR(int x,int y);
int isFull(int s);
int isEmpty(int s);
int POP(int size);
void PEEK(int size);
int CLEAR();
int BJPI(char dir,int x);
int CJPI(char dir);
void BACKTRACK(int size);
void RP(FILE *brain);
void Start();
