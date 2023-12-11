#include <stdio.h>
#include <stdlib.h>

void battle(int *Player, int *Computer, int *flag_ad) // continue:1,PlayerWin2,ComputerWin3
{
        printf("\n---------------------------\n");
    int playerhand = 0, playermaisuu = 0;
    int computerhand = 0, computermaisuu = 0;

    // Playerの手を入力する
    while (1)
    {
        printf("手を入力してください\n(グー:0 /チョキ:1/パー:2) ");
        scanf("%d", &playerhand);

        if ((playerhand != 0 && playerhand != 1 && playerhand != 2)||Player[playerhand]==0)
        {
            printf("手が存在しません。やり直してください。01\n");
        }
        else
        {
            switch (playerhand)
            {
            case 0:
                printf("グーが入力\n");
                break;

            case 1:
                printf("チョキが入力\n");
                break;

            case 2:
                printf("パーが入力\n");
                break;

            default:
                printf("エラー1");
                break;
            }
            break; // whileの外へ
        }
    }

    while (1)
    { // 枚数を決める
        printf("枚数を入力してください(%d枚まで出せます):", Player[playerhand]);

        if (scanf("%d", &playermaisuu)&(Player[playerhand] - playermaisuu < 0||playermaisuu==0))
        {
            printf("枚数エラーです.やりなおし02\n");
        }
        else{
            break;
        }
    }

    

    // Computerの手/枚数を決める
    while (1)
    {
        computerhand = rand() % 3;
        if (Computer[computerhand] == 0)
        {
            computerhand = rand() % 3;
        }
        else
        {
            break;
        }
    }
    computermaisuu = rand()%Computer[computerhand]+1;

    switch (playerhand)
            {
            case 0:
                printf("コンピュータ:グーを%d枚入力\n",computermaisuu);
                break;

            case 1:
                printf("コンピュータ:チョキを%d枚入力\n",computermaisuu);
                break;

            case 2:
                printf("コンピュータ:パーを%d枚入力\n",computermaisuu);
                break;

            default:
                printf("エラー1");
                break;
            }
    computermaisuu = rand() % Computer[computerhand] + 1;
    // 勝敗を決定する
    if((playerhand==0&&computerhand==1)||(playerhand==1&&computerhand==2)||(playerhand==2&&computerhand==0)){
    //plyerの勝利
    printf("playerの勝利!\n");
    Player[playerhand] -= playermaisuu;
    }
    else if((computerhand==0&&playerhand==1)||(computerhand==1&&playerhand==2)||(computerhand==2&&playerhand==0)){
    //computerの勝利
    printf("コンピュータの勝利!\n");
    Computer[computerhand] -= computermaisuu;
    }
    else{
        //あいこ
        printf("あいこ\n");
        Computer[computerhand] -=computermaisuu;
        Player[playerhand] -=playermaisuu;
    }
    printf("現在のプレイヤーの手札  : グー%d枚, チョキ%d枚,パー%d枚\n",Player[0],Player[1],Player[2]);
    printf("現在のコンピュータの手札枚数:%d枚\n",Computer[0]+Computer[1]+Computer[2]);

    if(Player[0]+Player[1]+Player[2] == 0){
        *(flag_ad) = 1;
    }
    else if(Computer[0]+Computer[1]+Computer[2] == 0){
        *(flag_ad) = 2;
    }
}

int main(void)
{
    int Player_Card[3] = {0};   // A[0]*G ,A[1]*C,A[2}*P
    int Computer_Card[3] = {0}; // A[0]*G ,A[1]*C,A[2}*P}
    int flag = 0;              // 勝敗フラグ0:inital 1:Player.2computer

    printf("ルール説明:\n 5枚のカードが初期手札(ランダム)\n一回のラウンドでどれかを出す(複数枚も可)\n手札を使い切った方が勝利\n");

    //手札決定
    int seed;
    for(int i=0;i<5;i++){
        seed = rand()%3;
        Player_Card[seed]++;

        seed = rand()%3;
        Computer_Card[seed]++;
    }

    printf("プレイヤーの手札 の初期手札: グー%d枚, チョキ%d枚,パー%d枚\n",Player_Card[0],Player_Card[1],Player_Card[2]);

    //勝敗がきまるまで
    while (!flag)

    { // flagが0以外になるまで繰り返し
        battle(Player_Card, Computer_Card, &flag);
    }
    switch (flag)
    {
    case 1:
        printf("おめでとう!!君の勝利!\n");
        break;
    
    case 2:
        printf("コンピュータの勝利!\n");
        break;

    default:
        printf("error 03");
        break;
    }

    return 0;
}
