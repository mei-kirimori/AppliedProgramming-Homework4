#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum Hands
{
    rock = 1,
    scissors = 2,
    paper = 3
};

class user
{
private:
    string name;
    Hands hand;
    int wincount;
    int losecount;
    int drawcount;

public:
    user(string setName)
    {
        name = setName;
        hand = rock;
        wincount = 0;
        losecount = 0;
        drawcount = 0;
    }

    void playerHand()
    {
        int input;
		cout << "出す手を入力してください" << endl << "グーなら１、チョキなら２、パーなら３" << endl;
        cin >> input;
        hand = static_cast<Hands>(input);
    }

    void enemyHand()
    {
        hand = static_cast<Hands>(rand() % 3 + 1);
    }

    Hands getHand()
    {
        return hand;
    }

    string getName()
    {
        return name;
    }

    void win()
    {
        ++wincount;
    }

    void lose()
    {
        ++losecount;
    }

    void draw()
    {
        ++drawcount;
    }

    void zyannkennInfo()
    {
        cout << name << endl;
        cout << "勝ち" << wincount << endl;
        cout << "負け" << losecount << endl;
        cout << "引き分け" << drawcount << endl;
    }
};

void zyannkennJudge(user* user1, user* user2)
{
    Hands hand1 = user1->getHand();
    Hands hand2 = user2->getHand();

    if (hand1 == hand2)
    {
        cout << "あいこ" << endl;
        user1->draw();
        user2->draw();
    }
    else if ((hand1 == rock && hand2 == scissors) ||
        (hand1 == scissors && hand2 == paper) ||
        (hand1 == paper && hand2 == rock))
    {
        cout << user1->getName() << "の勝ち" << endl;
        user1->win();
        user2->lose();
    }
    else
    {
        cout << user2->getName() << "の勝ち" << endl;
        user1->lose();
        user2->win();
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    user player("player");
    user enemy("enemy");

    player.playerHand();
    enemy.enemyHand();

    zyannkennJudge(&player, &enemy);

    player.zyannkennInfo();
    enemy.zyannkennInfo();
}