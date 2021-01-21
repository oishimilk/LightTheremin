# 光テルミン
## 説明
静電容量ではなく明るさで音程を制御するテルミンです。

## ビルド
1. Spresense の Arduino プロジェクトがビルドできる状態にします。
1. `theremin.ino` を Arduino IDE で開きます。
1. Spresense を PC に接続します。
1. Arduino IDE 上で `Ctrl+U` を押下し、スケッチをマイコンに書き込みます。

## 使い方
1. Spresense を PC に接続します。
1. シリアルモニタを開きます。
1. 準備ができた旨の表示があれば、スペースキーを送信します。
1. カメラ入力が明るくなると高い音、暗くなると低い音がヘッドホン端子に出力されます。なお、ボードを傾けることでも音階を変化させられます。

## 機能
シリアル通信を使用して各種機能にアクセスできます。以下に送信できるキーを示します。
- `v` 半音上げの切り替え
- `s` 状態表示（デバッグ用）
- `p` 短い休符
- `スペース` 出力の切り替え

## システムモデル
### 概要
![システムの概要図](assets/system_overview.png)

### コンテキスト図
![コンテキスト図](assets/system_context.png)

### 要求図
![要求図](assets/system_demand.png)

### アクティビティ図
![アクティビティ図](assets/system_activity.png)

### ブロック図
![ブロック図](assets/system_block.png)

### ユースケース図
![ユースケース図](assets/system_use_case.png)

## 動作デモ
### 音 ON/OFF
[![ON/OFFの様子](assets/thumb_onoff.png)](https://user-images.githubusercontent.com/56726852/105384195-471d2500-5c55-11eb-8e60-5a66fe335cf0.mp4)

### ピッチベンド
[![ピッチベンドの様子](assets/thumb_bend.png)](https://user-images.githubusercontent.com/56726852/105383622-a464a680-5c54-11eb-9923-b1a15c931828.mp4)

### 半音上げる
[![半音上げの様子](assets/thumb_sharp.png)](https://user-images.githubusercontent.com/56726852/105384406-83e91c00-5c55-11eb-8295-728ae4db4e97.mp4)

### 演奏
[![演奏の様子](assets/thumb_play.png)](https://user-images.githubusercontent.com/56726852/105384341-6ddb5b80-5c55-11eb-8fd3-6c0ce8d80286.mp4)
