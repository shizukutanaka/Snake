# Snake: GPUスケジューラ + Windows最適化ユーティリティ

本ソフトウェアは、Intel/NVIDIA/AMDなどの複数GPU環境で、GPUリソースを効率よくスケジューリングし、Windowsシステム全体のパフォーマンスを最適化するためのユーティリティです。

## 主な特徴
- 複数GPU（Intel/NVIDIA/AMD）混在環境に対応
- VRAM・ベンダ情報から最適なGPUを自動選択
- 主要アプリ（Chrome, Blender, Python等）を自動で高性能GPUに割り当て
- Windowsの電源プランも自動で高パフォーマンスに設定
- 完全自動化：ユーザー操作や監視ログ出力は不要
- C++17 / CMake対応

## ビルド方法

WindowsのコマンドプロンプトまたはPowerShellで以下を実行してください。

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## 実行方法

```
./Snake.exe
```

## 主な機能
- GPU一覧の表示（DXGIによる列挙）
- VRAM・ベンダをもとに最適なGPUを自動判定
- 主要アプリ（chrome.exe, blender.exe, python.exe等）が自動的に最適GPUを使うようWindowsのグラフィック設定（レジストリ）を自動変更
- 電源プランを自動で「高パフォーマンス」に設定
- ログ出力・手動操作・リアルタイム監視機能はありません

## 操作方法
1. プログラムを起動するだけでOKです。
2. GPU一覧と割り当て内容が表示され、自動で最適化が実行されます。
3. 主要アプリの割り当てや電源プラン設定も自動で完了します。
4. 手動操作やキー入力は不要です。
5. ※割り当て反映にはWindowsの再起動またはサインアウトが必要な場合があります。

## 寄付のお願い

本ソフトはMITライセンスのもと、無償で提供されています。継続的な開発のため、寄付をご検討いただければ幸いです。

**BTCアドレス:**
```
1GzHriuokSrZYAZEEWoL7eeCCXsX3WyLHa
```

## ライセンス

MIT License
