#include <raylib.h> 
#include <raymath.h>
#include <vector>
#include <string>
#include <utility> 

int SCREENWIDTH = 1280;
int SCREENHEIGHT = 720;

Vector2 GetMousePosInterscept()
{
    float ratio = SCREENWIDTH/640;
    return Vector2Scale(GetMousePosition(),1.0/ratio);
}


enum unit{
NONE,
KNIFE,
CANDLE,
VIOLIN,
BEARTRAP,
PAMPOEN,
KEY,
WATER,
STAKE,
PENCIl,
GRALIC,
SLINGSHOT,
KETTLE,
COIN,
CANE,
FLINTLOCK,
TEDDYBEAR,
CHAIR,
CLOCK,
BOOK,
PINKPOTION,
BLUEPOTION,
GREENPOTION,
ORANGEPOTION,
PICKAXE,
MIRROR,
NET,
AXE,
BOW,
PLANT,
DRUMSTICK,
PITCHFORK,
BOMB,
BROOM,
QUIL,
ROCK,
SICCORS
};

struct Die
{
    int side=-1;
    unit sides[6];
    bool hover,selected,placed;
    void randomise();
};

std::vector<unit> Grid;
unit to_use = unit::NONE;
int enemy_target = -1;


void GridSetup()
{
    for (int i =0; i< 9;i++)
    {
        for (int k=0;k<9;k++)
        {
            Grid.push_back(unit::NONE);
        }
    }
}

int GetCost(unit in)
{
    switch (in)
    {
        case unit::NONE:
                return 0;
                break;
        case unit::KNIFE:
                return 2;
            break;
        case unit::CANDLE:
                return 1;
            break;
        case unit::VIOLIN:
                return 4;
                break;
        case unit::PAMPOEN:
                return 1;
                break;
        case unit::BEARTRAP:
                return 6;
                break;
        case unit::KEY:
                return 1;
                break;                
        case unit::STAKE:
                return 2;
                break;
        case unit::WATER:
                return 1;
                break;
        case unit::PENCIl:
                return 2;
                break;
        case unit::GRALIC:
                return 6;
                break;
        case unit::SLINGSHOT:
                return 3;
                break;
        case unit::KETTLE:
                return 4;
                break;
        case unit::COIN:
                return 2;
                break;
        case unit::CANE:
                return 4;
                break;
        case unit::FLINTLOCK:
                return 5;
                break;
        case unit::TEDDYBEAR:
                return 6;
                break;
        case unit::CHAIR:
                return 3;
                break;
        case unit::CLOCK:
                return 1;
                break;
        case unit::BOOK:
                return 2;
                break;
        case unit::PINKPOTION:
                return 3;
                break;
        case unit::BLUEPOTION:
                return 3;
                break;
        case unit::GREENPOTION:
                return 3;
                break;
        case unit::ORANGEPOTION:
                return 3;
                break;
        case unit::PICKAXE:
                return 4;
                break;
        case unit::MIRROR:
                return 5;
                break;
        case unit::NET:
                return 3;
                break;
        case unit::AXE:
                return 3;
                break;
        case unit::BOW:
                return 2;
                break;
        case unit::PLANT:
                return 1;
                break;
        case unit::DRUMSTICK:
                return 2;
                break;
        case unit::PITCHFORK:
                return 6;
                break;
        case unit::BOMB:
                return 3;
                break;
        case unit::BROOM:
                return 1;
                break;
        case unit::ROCK:
                return 2;
                break;
        case unit::SICCORS:
                return 1;
                break;
        case unit::QUIL:
                return 1;
                break;    
    }
    return 80;
}

int GetDefence(unit in)
{
    switch (in)
    {
        case unit::NONE:
                return 0;
                break;
        case unit::KNIFE:
                return 2;
            break;
        case unit::CANDLE:
                return 1;
            break;
        case unit::VIOLIN:
                return 4;
                break;
        case unit::PAMPOEN:
                return 1;
                break;
        case unit::BEARTRAP:
                return 6;
                break;
        case unit::KEY:
                return 1;
                break;                
        case unit::STAKE:
                return 2;
                break;
        case unit::WATER:
                return 1;
                break;
        case unit::PENCIl:
                return 2;
                break;
        case unit::GRALIC:
                return 5;
                break;
        case unit::SLINGSHOT:
                return 3;
                break;
        case unit::KETTLE:
                return 4;
                break;
        case unit::COIN:
                return 2;
                break;
        case unit::CANE:
                return 4;
                break;
        case unit::FLINTLOCK:
                return 5;
                break;
        case unit::TEDDYBEAR:
                return 5;
                break;
        case unit::CHAIR:
                return 3;
                break;
        case unit::CLOCK:
                return 1;
                break;
        case unit::BOOK:
                return 2;
                break;
        case unit::PINKPOTION:
                return 3;
                break;
        case unit::BLUEPOTION:
                return 3;
                break;
        case unit::GREENPOTION:
                return 3;
                break;
        case unit::ORANGEPOTION:
                return 3;
                break;
        case unit::PICKAXE:
                return 4;
                break;
        case unit::MIRROR:
                return 5;
                break;
        case unit::NET:
                return 3;
                break;
        case unit::AXE:
                return 3;
                break;
        case unit::BOW:
                return 2;
                break;
        case unit::PLANT:
                return 1;
                break;
        case unit::DRUMSTICK:
                return 2;
                break;
        case unit::PITCHFORK:
                return 5;
                break;
        case unit::BOMB:
                return 3;
                break;
        case unit::BROOM:
                return 1;
                break;
        case unit::ROCK:
                return 2;
                break;
        case unit::SICCORS:
                return 1;
                break;  
        case unit::QUIL:
                return 1;
                break;     
              
    }
    return 80;
}

int GetAttack(unit in)
{
    switch (in)
    {
        case unit::NONE:
                return 0;
                break;
        case unit::KNIFE:
                return 4;
            break;
        case unit::CANDLE:
                return 1;
            break;
        case unit::VIOLIN:
                return 3;
                break;
        case unit::PAMPOEN:
                return 2;
                break;
        case unit::BEARTRAP:
                return 1;
                break;
        case unit::KEY:
                return 1;
                break;                
        case unit::STAKE:
                return 5;
                break;
        case unit::WATER:
                return 1;
                break;
        case unit::PENCIl:
                return 4;
                break;
        case unit::GRALIC:
                return 6;
                break;
        case unit::SLINGSHOT:
                return 4;
                break;
        case unit::KETTLE:
                return 5;
                break;
        case unit::COIN:
                return 1;
                break;
        case unit::CANE:
                return 3;
                break;
        case unit::FLINTLOCK:
                return 5;
                break;
        case unit::TEDDYBEAR:
                return 6;
                break;
        case unit::CHAIR:
                return 2;
                break;
        case unit::CLOCK:
                return 1;
                break;
        case unit::BOOK:
                return 2;
                break;
        case unit::PINKPOTION:
                return 3;
                break;
        case unit::BLUEPOTION:
                return 3;
                break;
        case unit::GREENPOTION:
                return 3;
                break;
        case unit::ORANGEPOTION:
                return 3;
                break;
        case unit::PICKAXE:
                return 3;
                break;
        case unit::MIRROR:
                return 3;
                break;
        case unit::NET:
                return 1;
                break;
        case unit::AXE:
                return 4;
                break;
        case unit::BOW:
                return 4;
                break;
        case unit::PLANT:
                return 1;
                break;
        case unit::DRUMSTICK:
                return 2;
                break;
        case unit::PITCHFORK:
                return 3;
                break;
        case unit::BOMB:
                return 4;
                break;
        case unit::BROOM:
                return 1;
                break;
        case unit::ROCK:
                return 5;
                break;
        case unit::SICCORS:
                return 3;
                break;  
        case unit::QUIL:
                return 1;
                break;   
    }
    return 80;
}


Rectangle TileToRect(unit u)
{
    

    switch (u)
    {
        case unit::NONE:
                return {0,0,0,0};
                break;
        case unit::KNIFE:
                return {0,0,32,32};
            break;
        case unit::CANDLE:
                return {32,0,32,32};
            break;
        case unit::VIOLIN:
                return {64,0,32,32};
                break;
        case unit::PAMPOEN:
                return {128,0,32,32};
                break;
        case unit::BEARTRAP:
                return {96,0,32,32};
                break;
        case unit::KEY:
                return {160,0,32,32};
                break;                
        case unit::STAKE:
                return {32,32,32,32};
                break;
        case unit::WATER:
                return {0,32,32,32};
                break;
        case unit::PENCIl:
                return {2*32,1*32,32,32};
                break;
        case unit::GRALIC:
                return {3*32,1*32,32,32};
                break;
        case unit::SLINGSHOT:
                return {4*32,1*32,32,32};
                break;
        case unit::KETTLE:
                return {5*32,1*32,32,32};
                break;
        case unit::COIN:
                return {0*32,2*32,32,32};
                break;
        case unit::CANE:
                return {1*32,2*32,32,32};
                break;
        case unit::FLINTLOCK:
                return {2*32,2*32,32,32};
                break;
        case unit::TEDDYBEAR:
                return {3*32,2*32,32,32};
                break;
        case unit::CHAIR:
                return {4*32,2*32,32,32};
                break;
        case unit::CLOCK:
                return {5*32,2*32,32,32};
                break;
        case unit::BOOK:
                return {0*32,3*32,32,32};
                break;
        case unit::PINKPOTION:
                return {1*32,3*32,32,32};
                break;
        case unit::BLUEPOTION:
                return {2*32,3*32,32,32};
                break;
        case unit::GREENPOTION:
                return {3*32,3*32,32,32};
                break;
        case unit::ORANGEPOTION:
                return {4*32,3*32,32,32};
                break;
        case unit::PICKAXE:
                return {5*32,3*32,32,32};
                break;
        case unit::MIRROR:
                return {0*32,4*32,32,32};
                break;
        case unit::NET:
                return {1*32,4*32,32,32};
                break;
        case unit::AXE:
                return {2*32,4*32,32,32};
                break;
        case unit::BOW:
                return {3*32,4*32,32,32};
                break;
        case unit::PLANT:
                return {4*32,4*32,32,32};
                break;
        case unit::DRUMSTICK:
                return {5*32,4*32,32,32};
                break;
        case unit::PITCHFORK:
                return {0*32,5*32,32,32};
                break;
        case unit::BOMB:
                return {1*32,5*32,32,32};
                break;
        case unit::BROOM:
                return {2*32,5*32,32,32};
                break;
        case unit::ROCK:
                return {3*32,5*32,32,32};
                break;
        case unit::SICCORS:
                return {4*32,5*32,32,32};
                break;  
        case unit::QUIL:
                return {5*32,5*32,32,32};
                break;   
    }
    
}

void DrawGrid(Texture2D &texture,Texture2D &dice_text)
{
    for (int i =0; i< 9;i++)
    {
        for (int k=0;k<9;k++)
        {
                 

            switch (Grid[i+k*9])
            {
            case unit::NONE:
                DrawTexture(texture,175+i*32,35+k*32,WHITE);                
                break;
            default:               
                DrawTexturePro(dice_text,TileToRect(Grid[i+k*9]),{175+(float)i*32,35+(float)k*32,32,32},{0,0},0.0,WHITE);
                DrawTexturePro(dice_text,{32*(float)(GetDefence(Grid[i+k*9])-1),192,32,16},{175+(float)i*32,35+(float)k*32,32,16},{0,0},0.0,WHITE);
            break;    
            }


            



            if (i+9*k == enemy_target)
            {
                DrawRectangle(175+i*32,35+k*32,32,32,Fade(RED,0.5));
            }

        }
    }
}



void DrawDice(Die dice[6],Texture2D &dice_text)
{
           
        int k =0;
        for (int i=0;i<6;i++)
        {
            if (i>2) {k =1;}
            if (dice[i].selected) {continue;}
            if (dice[i].placed) {continue;}
         
            
              


                DrawTexturePro(dice_text,TileToRect(dice[i].sides[dice[i].side]),{481+80*(float)k,67+((float)i-(float)k*3)*80,64,64},{0,0},0.0,WHITE);
              
                //DrawTexturePro(dice_text,{128,128,32,32},{481+80*(float)k,67+((float)i-(float)k*3)*80,64,64},{0,0},0.0,WHITE);



                DrawTexturePro(dice_text,{32*(float)(GetDefence(dice[i].sides[dice[i].side])-1),192,32,16},{481+80*(float)k,67+((float)i-(float)k*3)*80,64,32},{0,0},0.0,WHITE);
                DrawTexturePro(dice_text,{32*(float)(GetAttack(dice[i].sides[dice[i].side])-1),192+16,32,16},{481+80*(float)k,67+((float)i-(float)k*3)*80+32,64,32},{0,0},0.0,WHITE);



            if (dice[i].hover) {
                DrawRectangleLinesEx({481+80*(float)k,67+((float)i-(float)k*3)*80,64,64},4,{0,150,255,150});

                for (int j=0;j<GetCost(dice[i].sides[dice[i].side]);j++)
                {
                    DrawRectangle(374+j*6,325+26,4,8,Fade(YELLOW,0.4)); 
                }
        }
        }
}

void UpdateDice(Die dice[6])
{
        int k =0;
        for (int i=0;i<6;i++)
        {
            if (i>2) {k =1;}
            Rectangle d = {481+80*(float)k,67+((float)i-(float)k*3)*80,64,64};
            if (CheckCollisionPointRec(GetMousePosInterscept(),d))
            {
                dice[i].hover = true;
            }
          
        }
}



enum EnemyState{
    ATTACK,
    DEFEND,
    HYBRID
};


int main()
{
  
    InitWindow(SCREENWIDTH,SCREENHEIGHT,"DobbelMonster");
    InitAudioDevice();
    SetTargetFPS(60);
   
    Texture2D portaits = LoadTexture("./Assets/Portataits .png");
    Texture2D back_ground = LoadTexture("./Assets/game jam side table .png");
    Texture2D dice_idle = LoadTexture("./Assets/dice spin idle animation.png");
    Texture2D dice_transform = LoadTexture("./Assets/dice transformation .png");
    Texture2D end_turn_buton = LoadTexture("./Assets/End Turn GJ 2022.png");
    Texture2D roll_buton = LoadTexture("./Assets/Roll Button GJ 2022.png");
    Texture2D board = LoadTexture("./Assets/board.png");
    Texture2D dice_sheet = LoadTexture("./Assets/dicefinal.png");
    
    Sound Track1 = LoadSound("./Assets/Audio/game jam 2022 3 cut more energy.wav");
    Sound Track2 = LoadSound("./Assets/Audio/game jam 2022 2 cut.wav");
    Sound snd_enemey_hurt = LoadSound("./Assets/Audio/Enemy Hurt GJ 2022.wav");
    Sound snd_enemey_dice_die = LoadSound("./Assets/Audio/Enemy Dice Hurt GJ 2022.wav");
    Sound snd_player_hurt = LoadSound("./Assets/Audio/Player Hurt GJ 2022.wav");
    Sound snd_player_dice_die = LoadSound("./Assets/Audio/Player Dice Hurt GJ 2022.wav");
    Sound snd_roll_dice = LoadSound("./Assets/Audio/Dice Roll 2 GJ 2022 .wav");
    Sound snd_dice_place = LoadSound("./Assets/Audio/Dice Down GJ 2022.wav");
    Sound snd_error = LoadSound("./Assets/Audio/Wrong Move GJ 2022.wav");


    GridSetup();
    Die dice[6] = {
        {-1,{unit::KNIFE,unit::WATER,unit::COIN,unit::BOOK,unit::MIRROR,unit::PITCHFORK}},
        {-1,{unit::CANDLE,unit::STAKE,unit::CANE,unit::PINKPOTION,unit::NET,unit::BOMB}},
        {-1,{unit::VIOLIN,unit::PENCIl,unit::FLINTLOCK,unit::BLUEPOTION,unit::AXE,unit::BROOM}},
        {-1,{unit::BEARTRAP,unit::GRALIC,unit::TEDDYBEAR,unit::GREENPOTION,unit::BOW,unit::QUIL}},
        {-1,{unit::PAMPOEN,unit::SLINGSHOT,unit::CHAIR,unit::ORANGEPOTION,unit::PLANT,unit::ROCK}},
        {-1,{unit::KEY,unit::KETTLE,unit::CLOCK,unit::PICKAXE,unit::DRUMSTICK,unit::SICCORS}},
    };
    bool IsYourTurn = true;
    bool hoverOverEnd = false;
    int enemy_health = 10;
    int health_to_take = 0;
    int health = 10;
    int health_to_lose = 0;
    int monster_max_health = 10;
    int max_energy = 3;
    int current_energy = 3;
    Color EnergyColor = BLUE;
    std::string output_string("");
    Rectangle AttackZone = {4,4,142,142};
    EnemyState em_to_do = EnemyState::ATTACK;
    bool decided = false;
    std::vector<int> enemy_attacks;
    std::vector<std::pair<int,unit>> enemy_defenders;
    float enemy_action_timer=0;
    
    int which_enemy = 0;
    bool rolled_dice = false;
    float dice_roll_time = -1;
    float dice_animation_time =0;
    int dice_frame=0;
    bool track = true;

    Camera2D cam;
    cam.offset = {0,0};
    cam.target = {0,0};
    cam.rotation = 0.0;
    cam.zoom = SCREENWIDTH/640;
   
    int score = 0;

    
    for (auto &d:dice)
    {
        d.selected =false;
        d.placed = false;
    }

    PlaySound(Track1);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_Q))
        {
            SCREENWIDTH = 1920;
            SCREENHEIGHT = 1080;
            SetWindowSize(SCREENWIDTH,SCREENHEIGHT);
            
            cam.offset = {0,0};
            cam.target = {0,0};
            cam.rotation = 0.0;
            cam.zoom = SCREENWIDTH/640;
            continue;
        }

        if (IsKeyPressed(KEY_W))
        {
            ToggleFullscreen();
        }




            if (!IsSoundPlaying(Track1) && !IsSoundPlaying(Track2))
            {
                
                if (track) {PlaySound(Track2);}
                else PlaySound(Track1);

                track = !track;
            }


        dice_roll_time -= GetFrameTime();
        if (dice_roll_time > 0)
        {
            goto draw;
        }

        if (enemy_health <= 0)
        {
            output_string = "You Won!\n(Press end turn to \ncontinue)";
            
        }

        if (health <= 0)
        {
            output_string = "You Lost!\n(Press end turn to \nrestart)";
            
        }


        if (IsYourTurn)
        {
            dice_roll_time = -1.0;
            if (!decided)
            {
                decided = true;
                em_to_do = (EnemyState) GetRandomValue(0,2);
                switch (em_to_do)
                {
                case EnemyState::ATTACK:
                {
                    int health_to_take = GetRandomValue(3,6+(max_energy-3));
                    int total = 0;
                    while (total < health_to_take)
                    {
                        int n = GetRandomValue(1,4+(max_energy-3));
                        if (n+total <= health_to_take)
                        {
                            enemy_attacks.push_back(n);
                            total+=n;
                        }
                    } 
                }                
                    break;
                case EnemyState::DEFEND:
                {                  
                    int defenders = GetRandomValue(1,3+(max_energy-3));
                    int tot=0;
                    while (tot < defenders)
                    {
                        int n = GetRandomValue(1,36);
                        bool open = false;
                        bool placed = false;
                        int k=0;
                        int i =0;
                        while (!open && k<100)  
                        {
                            i = GetRandomValue(0,35);
                            open = (Grid[i]==NONE);
                            k++;
                        }   
                        for (auto &d:enemy_defenders)  
                        {
                            if (i==d.first)
                            {
                                placed=true;
                            }
                        }  
                        if (placed) {break;}

                        enemy_defenders.push_back({i,(unit)n});                        
                        tot++;
                    }
                }
                break;
                case EnemyState::HYBRID:
                {
                    int health_to_take = GetRandomValue(1,4);
                    int total = 0;
                    while (total < health_to_take)
                    {
                        int n = GetRandomValue(1,4);
                        if (n+total <= health_to_take)
                        {
                            enemy_attacks.push_back(n);
                            total+=n;
                        }
                    } 

                    int defenders = GetRandomValue(0,2);
                    int tot=0;
                    while (tot < defenders)
                    {
                        int n = GetRandomValue(1,36);
                        bool open = false;
                        bool placed = false;
                        int k=0;
                        int i =0;
                        while (!open && k<100)  
                        {
                            i = GetRandomValue(0,35);
                            open = (Grid[i]==NONE);
                            k++;
                        }     
                        for (auto &d:enemy_defenders)  
                        {
                            if (i==d.first)
                            {
                                placed=true;
                            }
                        }  
                        if (placed) {break;}            
                        enemy_defenders.push_back({i,(unit)n});                        
                        tot++;
                    }
                }
                break;
                }
                
                 

                    

            }






            for (auto &d:dice)
            {
                d.hover =false;
            }
            hoverOverEnd = false;
            UpdateDice(dice);

            if (CheckCollisionPointRec(GetMousePosInterscept(),{16,216+64,64,64}))
            {
                hoverOverEnd =true;
            }
            if  (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&&hoverOverEnd)
            {
                IsYourTurn =false;
                if (health<=0 || enemy_health <=0)
                {
                    if (health<=0 ) {score =0;}
                    if (enemy_health<=0 ) {score++;}
                    which_enemy+=(enemy_health <=0)?1:0;
                    if (which_enemy >2 ) {which_enemy=0;}
                    health = 10;
                    monster_max_health+=(enemy_health <=0)?3:0;
                    enemy_health = monster_max_health;
                    max_energy = 3;
                    current_energy =3;
                    IsYourTurn = true;
                    decided = false;
                    rolled_dice = false;
                    enemy_attacks.clear();
                    enemy_defenders.clear();

                  

                    for(auto &d:dice)
                    {
                        d.side = -1;
                    }
                    for(auto &g:Grid)
                    {
                        g = unit::NONE;
                    }
                    output_string = "";

                }


            }
            if (CheckCollisionPointRec(GetMousePosInterscept(),{16+64,216+64,64,64}) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&&!rolled_dice)
            {
                    for (auto &d:dice)
                    {
                        d.placed = false;
                        d.selected = false;
                        d.hover = false;
                        d.randomise();                       
                    }
                rolled_dice = true;
                dice_roll_time = 0.9;
                PlaySound(snd_roll_dice);
            }




            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&& (to_use == unit::NONE))
            {
            for (auto &d:dice)
            {
                if (d.hover&&!d.placed)
                {
                    if (d.side == -1) {break;}
                    to_use = d.sides[d.side];
                    d.selected = true;
                    EnergyColor = (GetCost(to_use)>current_energy)?RED:BLUE;
                    if (GetCost(to_use)>current_energy) {output_string ="Not Enougth Energy";PlaySound(snd_error);}

                }
            }
            } else
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&& (to_use != unit::NONE))
            {
                Vector2 m = GetMousePosInterscept();
                if (!(GetCost(to_use)>current_energy) &&CheckCollisionPointRec(m,{175,35+128,290,290-128}))
                {                    
                    m.x -= 175;
                    m.y -= 35;
                    int i = ((int)m.x/32);
                    int k = ((int)m.y/32);
                    Grid[i+k*9] = to_use;
                    current_energy -= GetCost(to_use);
                    for (auto &d:dice)
                    {
                        d.placed = d.selected;                        
                    } 
                    to_use = unit::NONE;
                    EnergyColor = BLUE;
                    PlaySound(snd_dice_place);
                    output_string = "";
                }
                else if (!(GetCost(to_use)>current_energy) &&CheckCollisionPointRec(m,AttackZone))
                {
                    bool Attack = true;
                    int i =0;
                    for (auto &g: Grid)
                    {
                            if ( i < 36)
                            {
                               if (g!=NONE)
                               {
                                Attack = false; 
                                PlaySound(snd_error);
                                output_string = "There are still\ndefenders on the\nBoard";                              
                                break;
                               }
                            }
                            i++;
                    }
                    
                    if(Attack)
                    {
                    enemy_health -= GetAttack(to_use);
                    current_energy -= GetCost(to_use);
                    for (auto &d:dice)
                    {
                        d.placed = d.selected;                        
                    } 
                    to_use = unit::NONE;
                    EnergyColor = BLUE;
                    PlaySound(snd_enemey_hurt);
                    }
                } 
                else 
                {   
                        m = GetMousePosInterscept();
                        m.x -= 175;
                        m.y -= 35;
                        int j = ((int)m.x/32);
                        int k = ((int)m.y/32);
                        int i =j+k*9;
                        if (i<36 && GetAttack(to_use)>=GetDefence(Grid[i]) && Grid[i]!=unit::NONE)
                        {
                            Grid[i] = unit::NONE;
                            current_energy -= GetCost(to_use); 
                            for (auto &d:dice)
                            {
                            d.placed = d.selected;                        
                            } 
                            to_use = unit::NONE;
                            EnergyColor = BLUE;
                            PlaySound(snd_enemey_dice_die);

                        }
                        




                   
                }
            }

            if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)&& (to_use != unit::NONE))
            {
            for (auto &d:dice)
            {
                d.selected = false;
            }
            to_use = unit::NONE;
            EnergyColor = BLUE;
            output_string = "";
            }

            health_to_take = 0;
            if (to_use!=NONE&&CheckCollisionPointRec(GetMousePosInterscept(),AttackZone))
            {
                health_to_take = GetAttack(to_use);

            }
            

        }
        else
        {
            hoverOverEnd = false;
            enemy_action_timer -= GetFrameTime();
            if (enemy_action_timer < 0)
            {
                
                if (!enemy_attacks.empty())
                {
                    if (enemy_target==-1)
                    {
                        int i =0;
                        for (auto &g: Grid)
                        {
                            if ( i >= 36)
                            {
                                if (g != unit::NONE)
                                {
                                    enemy_target = i;
                                    enemy_action_timer = 1.5;
                                    break;
                                }
                            }
                            i++;
                        }

                        if (health_to_lose == 0 && enemy_target==-1)
                        {
                            health_to_lose = enemy_attacks.back();
                            enemy_action_timer = 1.5;
                        }
                        else if (enemy_target==-1)
                        {
                            health -= enemy_attacks.back();
                            health_to_lose = 0;
                            enemy_attacks.pop_back();
                            enemy_action_timer = 1.5;
                            PlaySound(snd_player_hurt);
                        }                    

                    } else if (enemy_target != -1)
                    {
                        std::vector<int>::iterator itt = enemy_attacks.begin();
                        bool attacked = false;
                        for (auto &a:enemy_attacks)
                        {
                            if (a>=GetDefence(Grid[enemy_target]))
                            {
                                Grid[enemy_target] = unit::NONE;
                                enemy_target = -1;
                                enemy_action_timer=1.5;
                                enemy_attacks.erase(itt);
                                attacked = true;
                                PlaySound(snd_player_dice_die);

                                break;
                            }
                            itt++;
                        }
                        if (!attacked)
                        {
                            enemy_attacks.pop_back();
                            enemy_target = -1;
                            enemy_action_timer = 1.5;
                        }
                        
                    }

                }
                else if (!enemy_defenders.empty())
                {
                    Grid[enemy_defenders.back().first] = enemy_defenders.back().second;
                    enemy_defenders.pop_back();
                    enemy_action_timer = 1.5;
                }
                else
                {
                    IsYourTurn = true;
                    max_energy++;
                    current_energy = max_energy;
                    decided = false;
                    rolled_dice = false;
                    for(auto &d:dice)
                    {
                        d.side = -1;
                    }
                }




                
            }        








        }


draw:
        BeginDrawing(); 
        ClearBackground(RAYWHITE);
        BeginMode2D(cam);
        
        for (int i=0;i<5;i++)
        {
        DrawTexture(back_ground,0+back_ground.width*i,0,WHITE);
        }

        DrawTextureRec(portaits,{142*(float)which_enemy,0,142,142},{4,4},WHITE);


        DrawText("Energy:",374,325,22,EnergyColor);
        if (to_use == unit::NONE){            
        for (int i=0;i<current_energy;i++)
            DrawRectangle(374+i*6,325+26,4,8,EnergyColor);
        }
        else
        {
           for (int i=0;i<current_energy;i++)
           {
                if (i< current_energy-GetCost(to_use))
                {
                    DrawRectangle(374+i*6,325+26,4,8,EnergyColor); 
                } else
                {
                    DrawRectangle(374+i*6,325+26,4,8,Fade(EnergyColor,0.2));
                }            

           }
            
        }


        DrawGrid(board,dice_sheet);
        if(CheckCollisionPointRec(GetMousePosInterscept(),AttackZone)&&to_use !=NONE) DrawRectangleRec(AttackZone,Fade(RED,0.5));



        DrawRectangle(16,216,128,128,{0,255,0,100});
        DrawRectangle(16,216,128,64,BLACK);
        DrawText(output_string.c_str(),20,220,8,RAYWHITE);
        


        DrawTexture(end_turn_buton,16,280,WHITE);
        if (hoverOverEnd) DrawRectangleLinesEx({16,216+64,64,64},4,{0,150,255,150});

        DrawTexture(roll_buton,80,280,WHITE);
        if (CheckCollisionPointRec(GetMousePosInterscept(),{80,216+64,64,64})) DrawRectangleLinesEx({80,216+64,64,64},4,{0,150,255,150});


        if (rolled_dice && dice_roll_time < 0)
            DrawDice(dice,dice_sheet);
        else if (dice_roll_time < 0)
        {

        dice_animation_time += GetFrameTime();
        if (dice_animation_time > 0.8 ) {dice_frame++;dice_animation_time =0.0;} 
        if (dice_frame > 3) {dice_frame=0;}

        int k =0;
        for (int i=0;i<6;i++)
        {
            //DrawRectangle(481+80*k,67+(i-k*3)*80,64,64,BLACK);

            
            if (i>2) {k =1;}
            
            DrawTextureRec(dice_idle,{64*(float)dice_frame,0,64,64},{481+80*(float)k,67+((float)i-(float)k*3)*80},WHITE);

            if (dice[i].hover) {
                DrawRectangleLinesEx({481+80*(float)k,67+((float)i-(float)k*3)*80,64,64},4,{0,150,255,150});
            }
        }      
        }
        else 
        {
            dice_animation_time += GetFrameTime();
            switch (dice_frame)
            {
            case 0:
                if (dice_animation_time > 0.05) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;  
            case 1:
                if (dice_animation_time > 0.05) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;
            case 2:
                if (dice_animation_time > 0.05) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;     
            case 3:
                if (dice_animation_time > 0.05) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;           
            case 4:
                if (dice_animation_time > 0.25) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break; 
            case 5:
                if (dice_animation_time > 0.05) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break; 
            case 6:
                if (dice_animation_time > 0.1) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;
            case 7:
                if (dice_animation_time > 0.15) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;    
            case 8:
                if (dice_animation_time > 0.15) 
                {
                    dice_frame++;
                    dice_animation_time=0;
                }
                break;  
            }
        if (dice_frame > 8) {dice_frame=0;}

        int k =0;
        for (int i=0;i<6;i++)
        {
            //DrawRectangle(481+80*k,67+(i-k*3)*80,64,64,BLACK);

            
            if (i>2) {k =1;}
            
            DrawTextureRec(dice_transform,{64*(float)dice_frame,0,64,64},{481+80*(float)k,67+((float)i-(float)k*3)*80},WHITE);

            if (dice[i].hover) {
                DrawRectangleLinesEx({481+80*(float)k,67+((float)i-(float)k*3)*80,64,64},4,{0,150,255,150});
            }
        }

        }


        
        
        Vector2 m = GetMousePosInterscept();
        if (CheckCollisionPointRec(m,{175,35+128,290,290-128}))
        {
            m.x -= 175;
            m.y -= 35;
            m.x = ((int)m.x/32)*32.0 +175;
            m.y = ((int)m.y/32)*32.0+35;
            
        }
        
        switch (to_use)
        {           
            case unit::PAMPOEN:
                DrawRectangle(m.x,m.y,32,32,Fade(ORANGE,0.5));
                break;
            case unit::BEARTRAP:
                DrawRectangle(m.x,m.y,32,32,Fade(GRAY,0.5));
                break;
            case unit::STAKE:
                DrawRectangle(m.x,m.y,32,32,Fade(BROWN,0.5));
                break;
            case unit::WATER:
                DrawRectangle(m.x,m.y,32,32,Fade(BLUE,0.5));
                break;
            case unit::PENCIl:
                DrawRectangle(m.x,m.y,32,32,Fade(RED,0.5));
                break;
            case unit::GRALIC:
                DrawRectangle(m.x,m.y,32,32,Fade(GREEN,0.5));
                break;
            case unit::NONE:
            break;
            default:
                DrawRectangle(m.x,m.y,32,32,Fade(WHITE,0.5));
                break;
        }
        if (CheckCollisionPointRec(m,{175,35+128,290,290-128}))
        {
            if (GetDefence(to_use)>0) {DrawText(std::to_string(GetDefence(to_use)).c_str(),m.x+4,m.y,32,WHITE);}
        }



        

        

        DrawText("Monster Health:",176,4,22,PURPLE);
           for (int i=0;i<enemy_health;i++)
            {
                if (i< enemy_health-health_to_take)
                {
                    DrawRectangle(176+i*6,26,4,8,PURPLE); 
                } else
                {
                    DrawRectangle(176+i*6,26,4,8,Fade(PURPLE,0.2));
                }          
            }


            DrawText("Health:",176,325,22,RED);
            for (int i=0;i<health;i++)
            {
                if (i< health-health_to_lose)
                {
                    DrawRectangle(176+i*6,26+325,4,8,RED); 
                } else
                {
                    DrawRectangle(176+i*6,26+325,4,8,Fade(RED,0.2));
                }          
            }

            if (to_use!=NONE&&CheckCollisionPointRec(GetMousePosInterscept(),AttackZone))
            {
                DrawText(std::to_string(GetAttack(to_use)).c_str(),GetMousePosInterscept().x+8,GetMousePosInterscept().y,32,RAYWHITE);

            }
      
           
                
                for (auto &d:enemy_defenders)
                {
                int j=d.first;
                int i =0;
                int k =0;
                if (j<9) {i=j;k=0;}
                else if (j<18) {i=j-9;k=1;}
                else if (j<27) {i=j-18;k=2;}
                else if (j<36) {i=j-27;k=3;}               
                
                
                DrawTexturePro(dice_sheet,TileToRect(d.second),{175+(float)i*32,35+(float)k*32,32,32},{0,0},0.0,RED);

                }

                DrawText("Attacks Incoming:",420,4,22,RED);
                int i = 0;
                for (auto &a:enemy_attacks)
                {
                    DrawText(std::to_string(a).c_str(),420+50+i*24,4+26,22,RED);
                    i++;
                }

                DrawRectangleLinesEx({175,35,290,290},4,BLACK);
               

        DrawText("Score:",8,160,22,BLUE);
        DrawText(std::to_string(score).c_str(),110,160,22,BLUE);

        EndMode2D();
        EndDrawing();

    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

void Die::randomise()
{
    side=GetRandomValue(0,5);
}