# So_long Oyun Projesi

## 📝 Proje Hakkında
So_long, 42 Okulu müfredatının bir parçası olarak geliştirilen 2D bir oyun projesidir. Oyunda, karakterimiz harita üzerindeki tüm koleksiyon nesnelerini toplayıp çıkışa ulaşmaya çalışır.

## 🎮 Oyun Özellikleri
- 2D grafik arayüzü
- Duvarlarla çevrili harita
- Toplanabilir nesneler
- Tek çıkış noktası
- Hareket sayacı
- XPM formatında grafikler

## 🛠️ Teknik Özellikler
- MiniLibX grafik kütüphanesi kullanımı
- Harita doğrulama sistemi
- Flood-fill algoritması ile geçerli yol kontrolü
- Hafıza sızıntısı kontrolü
- Hata yönetimi

## 🗺️ Harita Gereksinimleri
- `.ber` uzantılı dosya
- Dikdörtgen şeklinde olmalı
- Duvarlarla çevrili olmalı
- Bir adet oyuncu (P)
- Bir adet çıkış (E)
- En az bir adet toplanabilir nesne (C)
- Geçerli karakterler: 0 (zemin), 1 (duvar), C, E, P

## 🎯 Oyun Kontrolleri
- `W` - Yukarı hareket
- `S` - Aşağı hareket
- `A` - Sola hareket
- `D` - Sağa hareket
- `ESC` - Oyundan çıkış

## 🚀 Kurulum ve Çalıştırma

1. Projeyi klonlayın:
bash
git clone <repo-url>

2. Projeyi derleyin:
bash
make

3. Oyunu başlatın:
bash
./so_long maps/<harita-adı>.ber

## 🔍 Önemli Fonksiyonlar

### Harita Kontrolleri
- `map_checker`: Harita dosyasının geçerliliğini kontrol eder
- `wall_control`: Duvar bütünlüğünü kontrol eder
- `is_missing`: Haritanın dikdörtgen olup olmadığını kontrol eder
- `flood_fill`: Geçerli bir yol olup olmadığını kontrol eder

### Oyun Mekanikleri
- `move_player`: Oyuncu hareketlerini yönetir
- `check_next_position`: Sonraki pozisyonun geçerliliğini kontrol eder
- `put_image`: Görselleri yükler
- `put_screen`: Ekranı günceller

## ⚠️ Hata Yönetimi
- Geçersiz harita formatı kontrolü
- Bellek yönetimi kontrolleri
- Ekran boyutu kontrolleri
- Oyun mantığı kontrolleri

## 🔧 Geliştirme Notları
- Tüm bellek sızıntıları kontrol edildi
- Norm kurallarına uygun kod yazıldı
- MiniLibX kütüphanesi etkin kullanıldı
- Hata yönetimi kapsamlı şekilde yapıldı
