#include <stdio.h>
#include <time.h>

// Tarih ve saat bilgisini saklayan yapý
struct TarihSaat {
    int yil, ay, gun, saat, dakika, saniye;
};

// Epoch zaman bilgisini saklayan birlik
union EpochZaman {
    time_t epoch;
};

// Tarihi epoch zamanýna çeviren fonksiyon
time_t cevirEpoch(struct TarihSaat ts) {
    struct tm zamanBilgi = {0};
    zamanBilgi.tm_year = ts.yil - 1900;
    zamanBilgi.tm_mon = ts.ay - 1;
    zamanBilgi.tm_mday = ts.gun;
    zamanBilgi.tm_hour = ts.saat;
    zamanBilgi.tm_min = ts.dakika;
    zamanBilgi.tm_sec = ts.saniye;
    return mktime(&zamanBilgi);
}

int main() {
    struct TarihSaat ts1, ts2;
    union EpochZaman epoch1, epoch2;
    
    // Kullanýcýdan ilk tarihi al
    printf("Birinci tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &ts1.yil, &ts1.ay, &ts1.gun, &ts1.saat, &ts1.dakika, &ts1.saniye);
    
    // Kullanýcýdan ikinci tarihi al
    printf("Ikinci tarihi giriniz (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &ts2.yil, &ts2.ay, &ts2.gun, &ts2.saat, &ts2.dakika, &ts2.saniye);
    
    // Epoch zamanýna çevir
    epoch1.epoch = cevirEpoch(ts1);
    epoch2.epoch = cevirEpoch(ts2);
    
    // Epoch zamanlarýný ekrana yazdýr
    printf("Birinci tarih epoch zamaný: %ld\n", epoch1.epoch);
    printf("Ikinci tarih epoch zamaný: %ld\n", epoch2.epoch);
    
    
    // Zaman farkýný hesapla ve yazdýr
    double fark = difftime(epoch2.epoch, epoch1.epoch);
    printf("Iki tarih arasindaki zaman farký: %.0f saniye\n", fark);
    
    return 0;
}
