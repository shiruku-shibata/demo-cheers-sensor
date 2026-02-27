# demo-cheers-sensor
乾杯のセンサー用リポジトリのデモ

開発環境はPlatformIOをVScodeの拡張機能で使用

---

## 目次

- [開発環境](#開発環境)
- [セットアップ](#セットアップ)
- [ブランチ戦略（Git Flow）](#ブランチ戦略git-flow)
- [開発フロー](#開発フロー)
- [ディレクトリ構成](#ディレクトリ構成)

---

## 開発環境

| ツール | バージョン |
|--------|-----------|
| VSCode | 最新版推奨 |
| PlatformIO IDE (VSCode拡張) | 最新版推奨 |
| Git | 2.x 以上 |

### 必要な VSCode 拡張機能

- [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

---

## セットアップ

### 1. リポジトリのクローン

```bash
git clone <リポジトリURL>
cd <プロジェクト名>
```

### 2. developブランチに切り替え

```bash
git checkout develop
```

### 3. VSCode でプロジェクトを開く

VSCode を起動し、PlatformIO のホーム画面から `Open Project` でクローンしたフォルダを開いてください。

依存ライブラリは PlatformIO が `platformio.ini` をもとに自動でインストールします。

---

## ブランチ戦略（Git Flow）

このリポジトリは **Git Flow** を採用しています。

```
master
  └── develop
        └── feature/xxx   （新機能・バグ修正）
        └── release/x.x.x （リリース準備）
              └── (master へマージ後タグ付け)
  └── hotfix/xxx          （緊急修正）
```

### 各ブランチの役割

| ブランチ | 役割 |
|----------|------|
| `master` | リリース済みの安定版。直接コミット禁止。タグで管理。 |
| `develop` | 開発の最新版。featureブランチをここにマージする。 |
| `feature/xxx` | 機能追加・バグ修正用。`develop` から派生し `develop` へ戻す。 |
| `release/x.x.x` | リリース前の最終調整用。`develop` から派生し `master` と `develop` へマージ。 |
| `hotfix/xxx` | 本番の緊急修正用。`master` から派生し `master` と `develop` へマージ。 |

---

## 開発フロー

### 新機能・バグ修正を行う場合

```bash
# developブランチから作業ブランチを作成
git checkout develop
git checkout -b feature/機能名

# 作業・コミット
git add .
git commit -m "feat: 機能の説明"

# developへマージ
git checkout develop
git merge feature/機能名

# 作業ブランチの削除（任意）
git branch -d feature/機能名
```

### リリースする場合

```bash
# developからreleaseブランチを作成
git checkout develop
git checkout -b release/1.0.0

# 最終調整後、masterとdevelopへマージ
git checkout master
git merge release/1.0.0
git tag -a v1.0.0 -m "Release v1.0.0"

git checkout develop
git merge release/1.0.0
```

### 緊急修正（hotfix）の場合

```bash
# masterから派生
git checkout master
git checkout -b hotfix/修正内容

# 修正後、masterとdevelopへマージ
git checkout master
git merge hotfix/修正内容
git tag -a v1.0.1 -m "Hotfix v1.0.1"

git checkout develop
git merge hotfix/修正内容
```

---

## ディレクトリ構成

```
.
├── src/                  # ソースコード
│   └── main.cpp
├── include/              # ヘッダーファイル
├── lib/                  # プロジェクト固有ライブラリ
├── test/                 # テストコード
├── platformio.ini        # PlatformIO設定ファイル
├── .gitignore            # PlatformIOが自動生成
└── README.md
```

> `.pio/` ディレクトリ（ビルド成果物）は `.gitignore` により自動的にバージョン管理から除外されます。
