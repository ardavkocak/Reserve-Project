# Rezerv Hesaplama Projesi

**C** dilinde yazılmış, **BGI grafik kütüphanesi (graphics.h)** kullanarak çok köşeli (poligon) şekillerin alanını **Shoelace (Gauss) formülü** ile hesaplayan, sonuçtan **rezerv değerini** çıkartan bir uygulama. Kocaeli Üniversitesi **Prolab 1** dersi kapsamında geliştirilmiştir.

## Özellikler

- **Uzaktan veri çekme**: `curl` ile `https://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt` adresinden satır tabanlı şekil verisi indirilir
- **Satır seçimi**: kullanıcı, çizdirmek istediği satırın etiketini girer (1–2 basamaklı)
- **Çoklu şekil desteği**: Aynı satırda 1, 2 veya 3 ayrı poligon olabilir; otomatik tespit edilir
- **Alan hesaplama**: Shoelace formülü ile her poligonun alanı bulunur, ölçek `16` ile düzeltilir
- **Rezerv değeri**: `toplamAlan × 10`
- **Maliyet girişleri**: sondaj maliyeti (0–10 arası) ve platform maliyeti kullanıcıdan alınır
- **İki pencereli görselleştirme**:
  1. Yeşil ızgaralı koordinat düzleminde mavi dolgulu poligonlar
  2. Siyah ızgaralı, eş karelere bölünmüş görünüm

## Gereksinimler

- **MinGW** + **WinBGIm** veya **Code::Blocks** (BGI grafik için)
- **curl** (PATH'de)
- Windows (BGI graphics.h Windows kütüphanesidir)

## Çalıştırma

Code::Blocks ile:
1. `Src/Alanformulu/Proje1.cbp` projesini açın
2. Derleyin ve çalıştırın
3. Konsoldan istenen değerleri girin:
   - Çizdirilecek **satır bilgisi** (txt dosyasındaki etiket)
   - **Sondaj maliyeti** (0–10)
   - **Platform maliyeti**

## Algoritma (özet)

1. `curl` ile txt dosyası indirilir, belleğe okunur
2. `indisDegeriniBul` ile istenen satırın `B` (başlangıç) işaretçisinden sonraki konumu bulunur
3. `F` (final) işaretine kadar `(x,y)` çiftleri taranıp `koordinatlar[][]` dizisine atılır
4. Tekrar eden başlangıç noktası ile şekil sayısı ve her şeklin kenar sayısı bulunur
5. `alanHesaplama` Shoelace formülünü uygular: `Σ(xᵢ·yᵢ₊₁ − xᵢ₊₁·yᵢ) / 2`
6. Alan, BGI penceresinde poligon olarak çizdirilir

## Dosya Yapısı

```
Src/
├── main.cpp                  # Ana uygulama (alan hesaplama + BGI)
├── Alanformulu/
│   ├── main.c                # Aynı uygulamanın C sürümü
│   ├── Proje1.cbp            # Code::Blocks proje dosyası
│   └── Proje1.depend / .layout
└── Curl ile kod cekme.txt    # curl kullanım notu
```

## Geliştiriciler

- Berk Karaoğlu
- Arda Koçak
