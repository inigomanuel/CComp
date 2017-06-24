#include "lvl.h"
#include <Personaje.h>
#include <Position.h>

lvl::lvl()
{
    windowGame = new MyWindow(MySize(40,15));
    Position t=windowGame->GetPosition();
    t.x+=3;
    t.y+=2;
    myPersonaje = new Personaje(t,'x');
    t.x=10;
    t.y=8;
    myEnemy = new Personaje(t,'&');
    t.x=16;
    t.y=9;
    myNpc = new Personaje (t,'o',"");
    t.x=20;
    t.y=18;
    myNpc1 = new Personaje (t,'s',"");
    MySize st=windowGame->GetMySize();

    t=windowGame->GetPosition();
    t.x++;
    t.y++;

    srand (time(NULL));
}

void lvl::Refresh()
{
    myPersonaje->Draw();
    myEnemy->Draw();
    myNpc->Draw();
    myNpc1->Draw();
    string xd="La leyenda de Kublay";
    stringstream hb;
    hb<<myPersonaje->GetHealth();
    windowGame->ShowMessage(Position(windowGame->GetMySize().width-xd.size()*1.5,1),xd);
    windowGame->ShowMessage(Position(0,3),string("Salud: ")+hb.str());
}

void lvl::ReachLimit(Personaje *b,Personaje *c,Position op)
{
    int g=0;
    Position i=c->GetPos();
    Position pb=b->GetPos();
    Position pw=windowGame->GetPosition();
    MySize sw=windowGame->GetMySize();
    if(pb.x==i.x&pb.y==i.y)
    {
        b->ChangePos(op);
    }
    if(pb.x > pw.x && pb.x < pw.x +sw.width-1 && pb.y > pw.y && pb.y < pw.y +sw.height-1)
        g=g+1;
    else
        b->ChangePos(op);

}

void lvl::GR1(Personaje *Kub,Personaje *Npc,Position retr)
{
    Position a,c;
    a=Kub->GetPos();
    c=Npc->GetPos();
    //cout<<a.x<<", "<<a.y<<" - "<<c.x<<", "<<c.y<<endl;

    if((a.x<=c.x+1&&a.x>=c.x-1)&&(a.y<=c.y+1&&a.y>=c.y-1))
    {
        //cout<<"ups"<<endl;
        //Kub->hit();
        //Kub->ChangePos(retr);
        windowGame->ShowMessage(Position(0,22),"Joven, me parece sensual");
    }
    else{
        windowGame->ShowMessage(Position(0,22),"                                                                                                           ");
    }

}

void lvl::GR2(Personaje *Kub,Personaje *Npc1,Position retr)
{
    Position a,d;
    a=Kub->GetPos();
    d=Npc1->GetPos();
    //cout<<a.x<<", "<<a.y<<" - "<<c.x<<", "<<c.y<<endl;

    if((a.x<=d.x+1&&a.x>=d.x-1)&&(a.y<=d.y+1&&a.y>=d.y-1))
    {
        //cout<<"ups"<<endl;
        //Kub->hit();
        //Kub->ChangePos(retr);
        windowGame->ShowMessage(Position(0,22),"Para encontrar el camino tiene que buscar al elfo");
    }
    else{
        windowGame->ShowMessage(Position(0,22),"                                                                                                           ");
    }

}

void lvl::GR(Personaje *Kub,Personaje *Enemy,Position retr)
{
    Position a,b;
    a=Kub->GetPos();
    b=Enemy->GetPos();
    if(a.x==b.x&a.y==b.y)
    {
        Kub->hit();
        Kub->ChangePos(retr);
        windowGame->ShowMessage(Position(0,21),"Ouch!");
    }
}

void lvl::Start()
{
    char c;
    bool endGame=false;
    windowGame->Draw();


    do
    {
        //Joven aqui esta avanzado, los aleatorios dl movimiento de los enemigos
        srand(static_cast <unsigned int> (time(0)));
        int val = rand() % 2 +0;
        int val2 = rand() % 2 +0;
        int val3 =  rand() % 2 +0;
        int c;
        (val3==0)?c=1:c=-1;
        Position nueva;
        nueva.x = val*c;
        nueva.y = val2*c;

        myEnemy->Move(nueva);

        Position pb=myPersonaje->GetPos();
        if(kbhit())
        {
            c = getch();


            switch (c)
            {
                case ESC:               // press ESC to exit
                    myPersonaje->hit() ;
                    break;
                case SPACE:               // press SPACE to clear screen
                    windowGame->ShowMessage(Position(0,21),myNpc->getDialogue());
                    break;
                case UP:
                    myPersonaje->Move(0,-1);
                    break;
                case DOWN:
                    myPersonaje->Move(0,1);
                    break;
                case LEFT:
                    myPersonaje->Move(-1,0);
                    break;
                case RIGHT:
                    myPersonaje->Move(1,0);
                    break;;
            }
        }
        ReachLimit(myPersonaje,myNpc,pb);

        GR(myPersonaje,myEnemy,pb);
        GR1(myPersonaje,myNpc,pb);


        Refresh();

        if(0==myPersonaje->GetHealth())
        {
            endGame=true;
            windowGame->ShowMessage(Position(0,21),string("Perdiste crrano color ianta"));
        }

   Sleep(100);

    }while(!endGame);

    windowGame->ShowMessage(Position(0,22),"The End...");
}

lvl::~lvl()
{
    delete windowGame;
}
