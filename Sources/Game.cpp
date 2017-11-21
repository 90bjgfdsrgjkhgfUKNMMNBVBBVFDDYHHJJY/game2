#include "Game.hpp"


// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A)
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B)
// TODO: 砲台を青い壁に沿って上下に動かす。(C)
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D)
// TODO: スコアのサイズを大きくする。(E)
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)
// TODO: PlayBGM()関数を使って、BGMを再生する。(G)
// TODO: PlaySE()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H)


Vector2 cloudPos;       //!< 雲の位置
Vector2 cannonPos;      //!< 砲台の位置
Vector2 bulletPos;      //!< 弾の位置
Rect    targetRect;     //!< ターゲットの矩形
int     score;          //!< スコア
vector<Vector2> bulletPosList;


// ゲーム開始時に呼ばれる関数です。
void Start()
{
    PlayBGM("bgm_maoudamashii_8bit07.mp3");  //(G)中西
    cloudPos = Vector2(-320, 100);
    cannonPos = Vector2(-310, -150);       //A:砲台の位置を画面左に(HW16A113 多田 亮太)
    targetRect = Rect(280, -140, 40, 40);  //A:ターゲットを画面右に(HW16A113 多田 亮太)
    bulletPos.x = -999;
    score = 0;
}

// 1/60秒ごとに呼ばれる関数です。モデルの更新と画面の描画を行います。
void Update()
{
    // 弾の発射
    if (bulletPos.x <= -999 && Input::GetKeyDown(KeyMask::Space)) {
        bulletPos = cannonPos + Vector2(50, 10);
        
    }

    void PlaySE();   //(H)中西
    
    if(Input::GetKeyDown(KeyMask::Space)) {
        PlayBGM("se_maoudamashii_explosion03.mp3");
    }
    
    
    // 弾の移動
    if (bulletPos.x > -999) {
        bulletPos.x += 150 * Time::deltaTime;
        if (bulletPos.x > 300) {
            bulletPos.x = -999;
        }

        // ターゲットと弾の当たり判定
        Rect bulletRect(bulletPos, Vector2(32, 20));
        if (targetRect.Overlaps(bulletRect)) {
            score += 100;         // スコアの加算(F HW16A108 相馬)
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
        }
    }

    // 背景の描画
    Clear(Color::cyan);
    FillRect(Rect(-320, -240, 640, 100), Color::green);

    // 雲の描画
    DrawImage("cloud1.png", cloudPos);
    cloudPos.x += 50 * Time::deltaTime;       //B:雲を左から右に移動(HW16A113 多田 亮太)
    if(cloudPos.x > 330) cloudPos.x = -510;   //B:雲が一番右に行ったら一番左に戻す(HW16A113 多田 亮太)

    // 弾の描画
    if (bulletPos.x > -999) {
        DrawImage("bullet.png", bulletPos);
    }

    // 砲台の描画
    FillRect(Rect(cannonPos.x-10, -140, 20, 100), Color::blue);
    DrawImage("cannon.png", cannonPos);
    

    // ターゲットの描画
    FillRect(targetRect, Color::red);

    // スコアの描画
<<<<<<< HEAD
    SetFont("nicoca_v1.ttf", 20.0f);
<<<<<<< HEAD
=======
    SetFont("nicoca_v1.ttf", 40.0f);//(E HW16A108相馬)
>>>>>>> 197d4d738149954422bfa7dc5fd441d30a75344a
    DrawText(FormatString("%02d", score), Vector2(-319, 199), Color::black);
    DrawText(FormatString("%02d", score), Vector2(-320, 200), Color::white);
    
    
    //プレイヤーの移動
    float cannonSpeed = 100.0f;
    
    if (Input::GetKey(KeyMask::DownArrow)) {
        cannonPos.y -= cannonSpeed * Time::deltaTime;
    }
    if (Input::GetKey(KeyMask::UpArrow)) {
        cannonPos.y += cannonSpeed * Time::deltaTime;
    }
    
    if (cannonPos.y < -145) {
        cannonPos.y = -145;
    } else if (cannonPos.y > -75) {
        cannonPos.y = -75;
    }
=======
    DrawText(FormatString("%05d", score), Vector2(-319, 199), Color::black);//(F HW16A108 相馬)
    DrawText(FormatString("%05d", score), Vector2(-320, 200), Color::white);//(F HW16A108 相馬)
>>>>>>> 59909df85cb6513000ef61010418166a37f28f1a
}
