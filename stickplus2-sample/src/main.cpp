#include <M5StickCPlus2.h>
/* M5StickC Plus端子仕様
  G0 :入力／出力／アナログ入力（無線使用時無効、内部で10kΩでプルアップ）
  G36:入力／ ―  ／アナログ入力
  G25:入力／出力／アナログ入力（無線使用時無効）／デジタル出力
  G26:入力／出力／アナログ入力（無線使用時無効）／デジタル出力
  G32:入力／出力／アナログ入力／Groveコネクタ(SDA）
  G33:入力／出力／アナログ入力／Groveコネクタ(SCL）
  　※G25/36はポートを共有しているため同時使用不可（使用しない方はフローティング入力にする）
  G37:本体ボタンA
  G39:本体ボタンB
  G35:本体ボタンC（6秒長押しで電源OFF）
  G19:本体LED（赤外線LEDと共用）
*/

// 端子割り付け
#define LED 19  // 本体LED

// 初期設定 -----------------------------------------
void setup() {
  auto cfg = M5.config();  // 本体初期化
  StickCP2.begin(cfg);

  // 出力端子設定
  pinMode(LED, OUTPUT);    // 本体LED赤
  digitalWrite(LED, LOW);  // 本体LED初期値OFF（LOW）

  // ベース画面の初期設定
  M5.Lcd.fillScreen(BLACK); // 背景色
  M5.Lcd.setRotation(1);  // 画面向き設定（USB位置基準 0：下/ 1：右/ 2：上/ 3：左）
  M5.Lcd.setTextSize(1);  // 文字サイズ（整数倍率）
}

// メイン -----------------------------------------
void loop() {
  M5.update();  //本体ボタン状態更新

  M5.Lcd.fillScreen(BLACK);  // 画面初期化
  // タイトル表示処理
  M5.Lcd.setFont(&fonts::Font4);        // M5GFXのフォントが指定可能（メモリ消費注意）
  M5.Lcd.setCursor(10, 5);              // 座標設定(x, y)
  M5.Lcd.setTextColor(WHITE, BLACK);    // 文字色指定(文字色, 背景)
  M5.Lcd.print("M5StickC Plus2 test");  // 表示内容

  // ライン表示
  M5.Lcd.drawFastHLine (0, 30, 240, WHITE);  // 指定座標から水平線（x, y, 長さ, 色）

  // 本体ボタンA処理
  M5.Lcd.setFont(&fonts::lgfxJapanGothicP_32);  // M5GFXのフォントが指定可能（メモリ消費注意）
  M5.Lcd.setCursor(15, 60);  // 座標設定(x, y)

  if (M5.BtnA.isPressed()) {  // ボタンAがONなら
    M5.Lcd.setTextColor(ORANGE, BLACK); // 文字色指定(文字色, 背景)
    M5.Lcd.print("ボタンA：ON");         // 表示内容
    digitalWrite(LED, HIGH);            // 本体LED点灯
  } else {                    // ボタンAがOFFなら
    M5.Lcd.setTextColor(CYAN, BLACK);   // 文字色指定(文字色, 背景)
    M5.Lcd.print("ボタンA：OFF");        // 表示内容
    digitalWrite(LED, LOW);             // 本体LED消灯
  }

  delay(100);  // 遅延時間（ms）
}