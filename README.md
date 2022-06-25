# Açık Kaynak Bilgisayar Bilimleri Eğitimi

Türkiye'de üniversitelerin bilgisayar mühendisliği, yazılım mühendisliği, bilgisayar bilimleri vb. bölümlerinde verilen eğitimin çoğunlukla bilgisayar bilimleri(computer science) eğitimi olması veya çok yakın olması ve bu doğrultuda CS eğitiminin günümüzde üniversiteler dışı, internetin olduğu her yerden -başta ingilizce olarak- alınabiliyor hale gelmesi, Türkçe kaynak tarafında bir Bilgisayar Bilimleri müfredatı hazırlama gereksinimi oluşturmuştur.

İster üniversitelerin çeşitli bölümlerinde bilgisayar bilimleri eğitimi alıyor olun, ister üniversite dışından bilgisayar bilimlerine ilgi duyuyor olun bu repoda dönem dönem sunulan dersleri çalışarak Computer Science eğtimi alabilirsiniz.

Aynı zamanda bu reponun esinlenildiği İngilizce versiyonu için göz atabilirsiniz: https://github.com/ossu/computer-science

*not: müfredat düzeni Türkiye'deki bilgisayar bilimleri eğitimi veren 4 yıllık(8 dönem) lisans bölümlerinin dersleri ve OSSU referans alınarak hazırlanılmıştır.*

# Müfredat


- [Müfredat](#mufredat)
- [1. Dönem](#1-donem)
  - [Ayrık Matematik (Discrete Mathematics)](#ayrik-matematikdiscrete-mathematics)
  - [C ile Programlamaya Giriş (Introduction to Programming)](#c-i̇le-programlamaya-girişintroduction-to-programming)
  - [Bilgisayar Bilimlerine Giriş (Introduction to Computer Science)](#bilgisayar-bilimlerine-girişintroduction-to-computer-science)
  - [Kalkülüs 1 (Calculus 1)](#kalkülüs-1-calculus-1)
  - [Lineer Cebir (Linear Algebra)](#lineer-cebir-linear-algebra)
- [2. Dönem](#2-donem)
  - [Kalkülüs 2 (Calculus 2)](#kalkülüs-2-calculus-2)
  - [Olasılık ve İstatistik (Probability and Statistics)](#olasılık-ve-i̇statistik-probability-and-statistics)
  - [Python ile Programlamaya Giriş (Introduction to programming with Python)](#python-i̇le-programlamaya-giriş-introduction-to-programming-with-python)
  - [Bilgisayar Bilimlerine Giriş 2 (Introduction to Computer Science)](#bilgisayar-bilimlerine-giriş-2-introduction-to-computer-science)
- [3. Dönem](#3-donem)
  - [Çizge Kuramı (Graph Theory)](#çizge-kuramı-graph-theory)
  - [Algoritmalar ve Veri Yapıları (Algorithms and Data Structures)](#algoritmalar-ve-veri-yapıları-algorithms-and-data-structures)
  - [Sayısal Çözümleme (Numerical Analysis)](#sayısal-çözümleme-numerical-analysis)
  - [Nesneye Yönelik Analiz ve Tasarım (Object-Oriented Analysis and Design (OOAD)](#nesneye-yönelik-analiz-ve-tasarım-object-oriented-analysis-and-design-ooad-)
  - [Sayısal Tasarım (Numerical Design)](#sayısal-tasarım-numerical-design)
- [4. Dönem](#4-donem)
  - [Veritabanı Yönetimi (Database Managment)](#veritabanı-yönetimi-database-managment)
  - [İşletim Sistemleri (Operating Systems)](#i̇şletim-sistemleri-operating-systems)
  - [Nesneye Yönelik Programlama (Object-Oriented Programming)](#nesneye-yönelik-programlama-object-oriented-programming)
  - [Matematiksel Programlama - Yöneylem Araştırması (Operations Research)](#matematiksel-programlama---yöneylem-araştırması-operations-research)
 - [Ara Dönem - Bilgisayar Bilimleri Eğitiminizin Eksik Dönemi](#ara-dönem---bilgisayar-bilimleri-eğitiminizin-eksik-dönemi)
- [5. Dönem](#5-dönem)
  - [Bulanık Mantık ve Bulanık Kümeler (Fuzzy Logic and Fuzzy Sets)](#bulanık-mantık-ve-bulanık-kümeler-fuzzy-logic-and-fuzzy-sets)
  - [Veri Madenciliğine Giriş (Introduction to Data Mining)](#veri-madenciliğine-giriş-introduction-to-data-mining)
  - [Algoritmaların Tasarımı ve Analizi (Design and Analysis of Algorithms)](#algoritmaların-tasarımı-ve-analizi-design-and-analysis-of-algorithms)
  - [Seçmeli Ders 1](#seçmeli̇-dersler)
  - [Seçmeli Ders 2](#seçmeli̇-dersler)
- [6. Dönem](#6-dönem)
  - [Kombinatoryal Optimizasyon (Combinatorial Optimization)](#kombinatoryal-optimizasyon-combinatorial-optimization)
  - [Bilgisayar Organizasyonu (Computer Organization)](#bilgisayar-organizasyonu-computer-organization)
  - [Bilgisayar Ağları (Computer Networks)](#bilgisayar-ağları-computer-networks)
  - [Seçmeli Ders 1](#seçmeli̇-dersler)
  - [Seçmeli Ders 2](#seçmeli̇-dersler)
- [7. Dönem](#7-dönem)
  - [Seçmeli Ders 1](#seçmeli̇-dersler)
  - [Seçmeli Ders 2](#seçmeli̇-dersler)
  - [Seçmeli Ders 3](#seçmeli̇-dersler)
  - [Seçmeli Ders 4](#seçmeli̇-dersler)
- [8. Dönem](#8-dönem)
  - [Seçmeli Ders 1](#seçmeli̇-dersler)
  - [Seçmeli Ders 2](#seçmeli̇-dersler)
  - [Seçmeli Ders 3](#seçmeli̇-dersler)
  - [Seçmeli Ders 4](#seçmeli̇-dersler)



---
Discord: https://discord.gg/7rX9TGQh
Telegram: https://t.me/computersciencelab - [https://t.me/csarchive](https://t.me/csarchive)



## 1. dönem
*Bu dönem  bilgisayar bilimleri için gerekli temel matematik derslerini ve bilgisayar bilimleri eğitimi için ön hazırlık yapacaksınız.*

#### C İle Programlamaya Giriş(Introduction to Programming)


Eğer daha önce hiç kod yazmadıysanız gelecekteki programcılık maceranızda dillerin soyutsal gelişimini anlayabilmeniz için C dili oldukça iyi bir başlangıç seçeneğidir.

**İşlenen bazı konular**:
`temel programlama yapısı`
`Pointer ile hafıza işlemleri`

Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[C Programlamaya Giriş(Murat Yücedağ)](https://www.youtube.com/watch?v=eIChume5VWQ&list=PLKnjBHu2xXNP-E_TjR-g5Tslm6dW4UH_3) | 60 video | 10 video/hafta | none | [chat](https://discord.gg/PUu2EeGS)
[Alternatif Kaynak: C Programlamaya Giriş(Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=gHmaZ2zeLu8&list=PL4eNZvHTpYhnACSWVmRBEr1MviDZ26b5E) | 18 video | 2 video/hafta | none | [chat](https://discord.gg/7rX9TGQh)

#### Bilgisayar Bilimlerine Giriş(Introduction to Computer Science)


Bilgisayar Bilimlerine Giriş dersi için kodluyoruz platformu çok harika iş çıkararak Harvard CS50 dersini Türkçeleştirip modül modül ilerleyebileceğiniz ve sonunda Kodluyoruz CS50 sertifikası alabileceğiniz bir platform oluşturmuş. 


Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Bilgisayar Bilimlerine Giriş(Introduction to Computer Science)](https://courses.kodluyoruz.org/courses/course-v1:Kodluyoruz+CS50x+2020/about)   | 10 hafta | 1 modül/hafta | Lineer Cebir | [chat](https://discord.gg/7rX9TGQh)



#### Kalkülüs 1 (Calculus 1)


Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 


Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Kalkülüs 1 (Calculus 1)](https://www.youtube.com/watch?v=jDZAAWzEH4k&list=PLcNWqzWzYG2v5_R_uPyLRzGXSoYgjfd8C) | 112 video | 11 video/hafta | none | [chat](https://discord.gg/7rX9TGQh)

#### Lineer Cebir (Linear Algebra)


Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 


Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--: | :--:
[Lineer Cebir (Linear Algebra)](https://www.youtube.com/watch?v=DJ7DoGoU9E0&list=PLcNWqzWzYG2vUwIrhpYTwqm0qboR5yQRA) | 146 video | 14 video/hafta | none | [chat](https://discord.gg/7rX9TGQh)

#### Ayrık Matematik (Discrete Mathematics)


Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 


Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Ayrık Matematik (Discrete Mathematics)](https://www.youtube.com/watch?v=Y5aJMTJqnKA&list=PLcNWqzWzYG2syBEQheDOG_5T8NplSYRyp)   | 211 video | 21 video/hafta | [chat](https://discord.gg/7rX9TGQh)


## 2. dönem 


#### Kalkülüs 2 (Calculus 2)

Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 



Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Kalkülüs 2 (Calculus 2)](https://www.youtube.com/watch?v=z7UBx7_QIVU&list=PLcNWqzWzYG2tsA_idtazrVigh_hG9Gjg3) | 111 video | 10 video/hafta | none | [chat](https://discord.gg/7rX9TGQh)


#### Olasılık ve İstatistik (Probability and Statistics)

Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 



Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Olasılık ve İstatistik (Probability and Statistics)](https://www.youtube.com/watch?v=gIwbGNK02Po&list=PLcNWqzWzYG2ufnZbJYffUkgYkhh3kS44L) | 117 video | 10 video/hafta | none | [chat](https://discord.gg/7rX9TGQh)

#### Python İle Programlamaya Giriş (Introduction to Programming With Python)

Geçtiğimiz 1. dönem programlama dünyasına C ile giriş yapmıştık. Bu dönem Python ile giriş yapacağız. Python sade ve kolay bir söz dizimine sahiptir. Ayrıca isterseniiz Olasılık ve istatistik dersinde aldığınız eğitimi Python'a ait Numpy, Pandas, Matplotlib gibi kütüphaneler ile kolaylıkla uygulamalı kullanarak veri bilimi dünyasına da göz kırpabilirsiniz. Diğer yandan Python ile kariyerinizi ilerletmek isterseniz veri bilimi yanı sıra yapay zeka, web geliştirme, siber güvenlik gibi pek çok konuda uzmanlık elde edebilirsiniz.



Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Python İle Programlamaya Giriş (Introduction to Programming With Python)](https://www.youtube.com/watch?v=EzHgbO1Cee4&list=PLWctyKyPphPiul3WbHkniANLqSheBVP3O) | 62 video | 6 video/hafta | none | [chat](https://discord.gg/syA242Z)
[Alternatif: Sıfırdan İleri Seviyeye Python(sertifikalı)](https://www.btkakademi.gov.tr/portal/course/sifirdan-ileri-seviye-python-programlama-5877) | 43 saat | 4 saat/hafta | none | [chat](https://discord.gg/7rX9TGQh)

#### Bilgisayar Bilimlerine Giriş 2 (Introduction to Computer Science)

Bilgisayar Bilimlerine Giriş dersi, ilerde göreceğiniz yoğun matematik ve yazılım derslerine hazırlık yapmanız ve gelecekte seçeceğiniz alanı bulmanız için önemlidir. 


Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Bilgisayar Bilimlerine Giriş(Prof. Dr. Kemal Bıçakçı)](https://www.youtube.com/watch?v=xtN_nKSHfQc&list=PLmPsb7nQhv7N2QTb7fggPSmWmdOi5dGQZ)   | 10 Video | 1 video/hafta | Lineer Cebir | [chat](https://discord.gg/7rX9TGQh)



## 3. dönem 


#### Çizge Kuramı (Graph Theory)

Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 



Ders | Süre | Efor | Önkoşul | Tartışma
:-- | :--: | :--: | :--: | :--:
[Çizge Kuramı (Graph Theory)](https://www.youtube.com/watch?v=PYAxAUUKZ84&list=PLcNWqzWzYG2vmvMLwSpza7IyV0oqoGLjg) | 48 video | 5 video/hafta | none | [chat](https://discord.gg/PUu2EeGS)
[Ek Kaynak: Çizge Kuramı (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=paMcKZlcv78) | 1 video | - | none | [chat](https://discord.gg/7rX9TGQh)


#### Algoritmalar ve Veri Yapıları (Algorithms and Data Structures)

1. dönem gördüğünüz C derslerini bu derste çeşitli algoritmalar üzerinde kullanarak bilgisayar bilimlerinde veri yapılarının nasıl oluştuğunu daha iyi anlayacaksınız.



Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Algoritmalar ve Veri Yapıları (Algorithms and Data Structures)](https://www.youtube.com/watch?v=r3uOBb3BM-0&list=PLh9ECzBB8tJN9bckI6FbWB03HkmogKrFT) | 26 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Python İle Veri Yapıları (Algorithms and Data Structures With Python)](https://www.youtube.com/watch?v=V7yZ69pgJKU&list=PLh9ECzBB8tJOoFYmIIiwFjgXDCD9uiD_i) |  |  |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak:Veri Yapıları (Algoritma Uzmanı)](https://www.youtube.com/watch?v=lTFmKiyo0nU&list=PLUUSh8du1azZEsdngPxMQGLnatId0V4h9) |  |  |  [chat](https://discord.gg/7rX9TGQh)

#### Sayısal Çözümleme (Numerical Analysis)

Bilgisayar Bilimleri, matematik disiplininden köken alarak gelişmiş bir disiplindir. Bilgisayar Bilimci olmak için muhakkak gerekli matematik derslerini almalısınız. 



Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Sayısal Çözümleme (Numerical Analys)](https://www.youtube.com/watch?v=t69PeA210U8&list=PLcNWqzWzYG2s5lVEJJK-TPivoT5VS_WTK) | 99 video | 10 video/hafta |  [chat](https://discord.gg/7rX9TGQh)

#### Nesneye Yönelik Analiz ve Tasarım (Object-Oriented Analysis and Design (OOAD) )

Bilgisayar Bilimlerinin bilhassa Yazılım Mühendisliği ve Gereksinim Mühendisliği kollarını ilgilendiren Nesne Yönelimli Çözümleme ve Tasarım dersi, bir sistemin/sistem modülleri setinin/organizasyonun/işletme biriminin gereksinimlerinin çözümlenmesi ve uygun bir çözümün tasarımında nesne ile modelleme tekniklerini kullanılması üzerinedir.


Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Nesneye Yönelik Analiz ve Tasarım (Object-Oriented Analysis and Design (OOAD)](https://www.youtube.com/watch?v=pUGHbEGQj0g&list=PLh9ECzBB8tJOmOydGaV7xr9h13ooEjBkV) | 31 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Object-Oriented Analysis and Design (OOAD)](https://www.youtube.com/watch?v=IzN9Vuoivrg&list=PL6XklZATqYx9dj72MKG6wLYjljeB2odra&index=1) | 14 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)


#### Sayısal Tasarım (Numerical Design)

Bilgisayar Bilimleri eğitimi alırken bilgisayar donanımına Sayısal Tasarım dersiyle giriş yapacağız.


Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Sayısal Tasarım (Numerical Design)](https://www.youtube.com/watch?v=q3cjsh3Ur2g&list=PLdcoZed79ZuckfFQIT_t8PQuSBHFK_H-s) | 106 video | 10 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Alternatif Kaynak(Kitap): Sayısal Tasarım - Morris Mano] | 500 sayfa | - |  [chat](https://discord.gg/7rX9TGQh)


## 4. dönem 


#### Veritabanı Yönetimi (Database Managment)

Veritabanı yönetimi dersiyle veritabanı mühendisliğinin ilgilendiği konuların temellerini alacaksınız.

**İşlenen bazı konular**:
`Varlık İlişki Diyagramı - ERD `
`Normalizasyon`
`İlişkisel Veritabanları`
`SQL - NoSQL`

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Veritabanı Yönetimi (Database Managment)](https://www.youtube.com/watch?v=pHKZw5EyTi4&list=PLh9ECzBB8tJOS7WQKdeUaAa5fmPLYAouD) | 20 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Veritabanı Yönetimi (Erdinç Uzun)](https://www.youtube.com/watch?v=1xhO7dlSlwE&list=PLq4n-UisAJbIYbb7B-eE3deU_W1p6bPB4&index=1) | 1 video | - | [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Uygulamalarla SQL Öğreniyorum(Sertifikalı)](https://www.btkakademi.gov.tr/portal/course/uygulamalarla-sql-oegreniyorum-8249) |  |   | [chat](https://discord.gg/7rX9TGQh)

#### İşletim Sistemleri (Operating Systems)

Bilgisayar Bilimlerinin en önemli derslerinden birisi olan İşletim Sistemleri dersi ile bir işletim sisteminin temel yapısının ne olduğunu, organizasyonlar arasındaki iletişimin nasıl gerçekleştiğini anlamak için iyi bir şekilde öğrenmeniz gereken bir dersttir.


Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[İşletim Sistemleri (Operating Systems)](https://www.youtube.com/watch?v=r2q_XRKrqHQ&list=PLh9ECzBB8tJO9eiwfQbcA2ThMbUSkbOWf) | 33 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)


#### Nesneye Yönelik Programlama (Object-Oriented Programming)

Programcılık hayatınızda yazılım mühendisliğinin temelini oluşturan OOP konusunu mutlaka iyi anlamalısınız. İlgilendiğiniz programlama diline ait OOP eğitimini alabilirsiniz.



Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Python ile Nesneye Yönelik Programlama (Object-Oriented Programming)](https://python-istihza.yazbel.com/nesne_tabanli_programlama1.html) | 30 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Java ile Nesneye Yönelik Programlama (Object-Oriented Programming)](https://www.youtube.com/watch?v=H_SKv07-648&list=PLh9ECzBB8tJPFTpuHKhYayis0H9pS6_rI) | 36 video | 4 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[C# ile Nesneye Yönelik Programlama (Object-Oriented Programming)](https://www.youtube.com/watch?v=TC-QxmF_sFk&list=PLIM5iw4GHbNWdLUPpLr-BcAJJ0-7a1i2s) | 38 video | 4 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[C++ ile Nesneye Yönelik Programlama (Object-Oriented Programming)](https://www.youtube.com/watch?v=5b-UJWfr73c&list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q) | 49 video | 5 video/hafta |  [chat](https://discord.gg/7rX9TGQh)



#### Matematiksel Programlama - Yöneylem Araştırması (Operations Research)

Yöneylem araştırması, belirli kısıtların olduğu bir durumda, belirli bir amaca yönelik en uygun çözümün bulunması için geliştirilmiş bir yöntemdir. Bilgisayar Bilimleri ile olan ilişkisi, Yöneylem Araştırması'nın araştırma konularının; istatistik, optimizasyon, rassallık, kuyruk kuramı, oyun kuramı, çizge kuramı, karar analizi ve simülasyon olmasından gelmektedir.

Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Matematiksel Programlama - Yöneylem Araştırması (Operations Research)](https://www.youtube.com/watch?v=ahTEzQm-220&list=PLw1-Fksmff1uptTl-uiZvBZkZOa4wrSBk) | 32 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Alternatif Kaynak: Matematiksel Programlama - Yöneylem Araştırması (Operations Research)](https://www.youtube.com/watch?v=ovVY0_92OS4&list=PLcNWqzWzYG2tMf8yy0_m1q4VLkNiHqurz) | 35 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)



## Ara Dönem - Bilgisayar Bilimleri Eğitiminizin Eksik Dönemi
Ara dönemde MIT Computer Science bölümünde "The Missing Semester of Your CS Education" adı verilen "Bilgisayar Bilimleri Eğitiminizin Eksik Dönemi"  dersini göreceksiniz. 

Ders | Süre | Efor | Tartışma
:-- | :--: | :--: | :--:
[Bilgisayar Bilimleri Eğitiminizin Eksik Dönemi (The Missing Semester of Your CS Education)](https://missing-semester-tr.github.io/) | 2 hafta | 6 saat/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Orjinal İngilizce Versiyon](https://missing.csail.mit.edu/) | 2 hafta | 6 saat/hafta |  [chat](https://discord.gg/7rX9TGQh)


## 5. dönem 
Bu dönem 2 adet seçmeli dersi seçmeli ders listesinden seçmeniz gerekiyor.


#### Bulanık Mantık ve Bulanık Kümeler (Fuzzy Logic and Fuzzy Sets)

Bulanık mantık bir yapay zekâ uygulaması oluşturma prensibidir.


Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Bulanık Mantık ve Bulanık Kümeler (Fuzzy Logic and Fuzzy Sets)](https://www.youtube.com/watch?v=YZ9cEUysr5o&list=PLDUOF2Be-kzk8h239p-5knu-D1uR5h33_) | 21 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Bulanık Mantık ve Bulanık Kümeler (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=SQowmSHCjuU&t=339s) |  | - | [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Fuzzy Logic(İngilizce)](https://www.youtube.com/watch?v=hxanquMn3eU&list=PLUVnh0w_cCjIzH0i8B6yQcXs567mST9cQ) |  |   | [chat](https://discord.gg/7rX9TGQh)

#### Veri Madenciliğine Giriş (Introduction to Data Mining)

Veri madenciliği, büyük ölçekli veriler arasından faydalı bilgiye ulaşma, bilgiyi madenleme işidir.

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Veri Madenciliğine Giriş (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=k5XNy2XmvOE&list=PLh9ECzBB8tJP8THd6b8DJmw76G6cyPo3o) | 69 video | 7 video/hafta | [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak:Teorik Veri Madenciliği  (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=iButBaRPpBM&list=PLh9ECzBB8tJNScCBWJFoMdpMkCdpnwUEl) | 12 video | 2 video/hafta | [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak:Veri Madenciliği ve İstatistiksel Yöntemler  (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=iButBaRPpBM&list=PLh9ECzBB8tJNScCBWJFoMdpMkCdpnwUEl) | 19 video | 2 video/hafta | [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Veri Madenciliğine Giriş (Introduction to Data Mining)](https://www.youtube.com/watch?v=niXG2zCXj00&list=PLNVCj-z_HS4YpUuNJ-XbPrfeThCF-ROeb) | 32 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)


#### Algoritmaların Tasarımı ve Analizi (Design and Analysis of Algorithms)

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Algoritmaların Tasarımı ve Analizi (Design and Analysis of Algorithms)](https://www.youtube.com/watch?v=3bhBo9YCTpo&list=PLh9ECzBB8tJPTWIUbZjHZMMGuZcpHUv5h) | 21 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Algoritmaların Tasarımı ve Analizi (Design and Analysis of Algorithms)](https://www.youtube.com/watch?v=_eFseY9EwjM&list=PLfs1gAT4S8yIGKkJw4gbz2ZdmuEBxjGwk) |  | - | [chat](https://discord.gg/7rX9TGQh)


## 6. dönem 
Bu dönem 2 adet seçmeli dersi seçmeli ders listesinden seçmeniz gerekiyor.


#### Kombinatoryal Optimizasyon (Combinatorial Optimization)
Çözüm kümesi discrete olan optimizasyon problemleridir. Bilgisayar Bilimleri'nin yapay zeka, yazılım mühendisliği ve uygulamalı matematik alanları ile yakından ilgilidir.

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Kombinatoryal Optimizasyon (Combinatorial Optimization)](https://www.youtube.com/watch?v=G27vjNQUoh4&list=PLXsmhnDvpjORcTRFMVF3aUgyYlHsxfhNL) | 71 video | 7 video/hafta |  [chat](https://discord.gg/7rX9TGQh)

#### Bilgisayar Organizasyonu (Computer Organization)
Bilgisayar Bilimleri'nde bilgisayar organizasyonu, (veya bazen mikromimari de denir) verilen bir komut kümesi mimarisinin bir işlemci üzerinde gerçeklenmesidir.

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Bilgisayar Organizasyonu (Computer Organization)](https://www.youtube.com/watch?v=XeAhz1bp1BY&list=PLvNq8wrSYGAU6CF4UleG6HbXa9paQDsLK) | 47 video | 5 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Morris Mano Bilgisayar Sistemleri Mimarisi Kitabı] | 500 sayfa | - |  [chat](https://discord.gg/7rX9TGQh)

#### Bilgisayar Ağları (Computer Networks)
Bilgisayar Ağları dersini alan öğrenciler bilgisayar ağlarının temel prensipleri, iletişim protokol yapısı ve işlevleri, protokol katmanları ve aralarındaki ilişkileri ve kısmi ağ güvenliği hakkında bilgi sahibi olacaktır.

Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Bilgisayar Ağları (Computer Networks)](https://www.youtube.com/watch?v=b573S89IhhA&list=PL1XUdfGZZ4rQ0UPDx__7W4LmeLab227vb) | 46 video | 5 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Ek Kaynak: Bilgisayar Ağları Ve İnternet - Douglas E. Comer Kitabı] | 662 sayfa | - |  [chat](https://discord.gg/7rX9TGQh)


## 7. dönem 
Bu dönem 4 adet seçmeli dersi seçmeli ders listesinden seçmeniz gerekiyor.

## 8. dönem 
Bu dönem 4 adet seçmeli dersi seçmeli ders listesinden seçmeniz gerekiyor.

## SEÇMELİ DERSLER
İlgili dönemlere dair ders seçimlerinizi aşağıdaki listeden yapabilirsiniz.


Ders | Süre | Efor |  Tartışma
:-- | :--: | :--: | :--:
[Siber Güvenliğe Giriş (Prof. Dr. Kemal Bıçakçı)](https://www.youtube.com/watch?v=dVdzS9O17ww&list=PLmPsb7nQhv7MHAfbyYD7-jKXAL4KRqvU2) | 14 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Programlama Dilleri Prensipleri (Doç. Dr. Erdinç Uzun)](https://www.youtube.com/watch?v=x0CQyCeW7KY&list=PLq4n-UisAJbJdLkxKgVqJZ2Qk1zitUZ9D) | 109 video | 11 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Kriptoloji Bilimine Giriş (Dr. Fatih Özkaynak)](https://www.youtube.com/watch?v=0RECW49LmHM&list=PLR_3k5Bkz0SAgl6aeXR-4_3Gtv9rywoBa) | 42 video | 5 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Çok Değişkenli Veri Analizi (Doç. Dr. Oktay Bektaş)](https://www.youtube.com/watch?v=2aUcgFfwFis&list=PLdegw8CWM59kYWeELSQFH-UBk8e0MC_Ni) | 32 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Yazılım Mühendisliği (Dr. Fatih Özkaynak)](https://www.youtube.com/watch?v=-2tzE5NWDPI&list=PLR_3k5Bkz0SBGQHDvzoYk0FU3UUbTQSWz) | 12 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Linux Giriş (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=_Kc9ImFpqro&list=PLh9ECzBB8tJOnxXrUTOqXfurKOZkN4mEY) | 16 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Mobil Programlama (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=S-A59CoIrEQ&list=PLh9ECzBB8tJNBk3dm8XGtYv_xOk9CTdst) | 25 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Web Programlama (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=BNSwq1PTE8M&list=PLh9ECzBB8tJN9WuXjJEZvPf4q9LZhA1bO) | 18 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Yapay Zeka (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=1xOe1vc-dJw&list=PLh9ECzBB8tJOtaD6DFxqRdP7QHIaBFcbW) | 48 video | 5 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[İnternet Nasıl Çalışır? (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=jVsUOiBzu7o&list=PLh9ECzBB8tJMKXMd8ovXR8TmQeaVtz5-l) | 15 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Rapid Miner - Veri Madenciliği (Prof. Dr. Şadi Evren Şeker)](https://www.youtube.com/watch?v=mFO2fGYzMgQ&list=PLh9ECzBB8tJN-rTkIyGIDJwTRBNSIZwTQ) | 18 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Uygulamalı Kriptografi (Prof. Dr. Çetin Kaya Koç)](https://www.youtube.com/watch?v=r7no3eREtgE&list=PLWtwsoCi5xAE6_ixlYHqw0Ej-q-_S64oV) | 15 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Kriptografi Mühendisliği (Prof. Dr. Çetin Kaya Koç)](https://www.youtube.com/watch?v=r4ztwZXkG94&list=PLWtwsoCi5xAELiiXTy7lbDxD_q0byP_OY&index=10) | 10 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Sayısal Sinyal İşleme(Elektronik Okulu)](https://www.youtube.com/watch?v=0t_-PGYOBtk&list=PLLqNamRiKS5f9xV24u3bttAetQFE0LZF2) | 54 video | 6 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Bilgisayar Grafikleri (Dr. Cengiz Güngör)](https://www.youtube.com/watch?v=Qo4A-MQTarE&list=PLUR6lZV92DNRCv1gd_y1L3PZabM53ujaH) | 27 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Paralel Hesaplama  (Dr. Cengiz Güngör)](https://www.youtube.com/watch?v=ok7Dp4CUKpM&list=PLUR6lZV92DNTctMQc7UFVj4usrFVxp1l5) | 20 video | 2 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Hesaplama Kuramına Giriş - Biçimsel Diller ve Otomatlar (Prof.Dr. NEJAT YUMUŞAK)](https://www.youtube.com/watch?v=JNmDsQqF8Hk&list=PLDUOF2Be-kzmLZ2uHD09cG4VKV0rihr-a) | 9 video | 1 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Nesnelerin İnternetinin Temelleri  (BTKAkademi - Sertifikalı)](https://www.btkakademi.gov.tr/portal/course/nesnelerin-interneti-iot-ve-guevenligi-10625) | 23 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Gömülü Sistem Programlama  (Süleyman ŞEKER)](https://www.youtube.com/watch?v=Qwyf1HJ_zgg&list=PLeKWVPCoT9e3Txa-PKwO6fC37JfUU9dbo) | 30 video | 3 video/hafta |  [chat](https://discord.gg/7rX9TGQh)
[Bash Script Temel Eğitimi  (Süleyman ŞEKER)](https://www.youtube.com/watch?v=PN211ARk84M&list=PLeKWVPCoT9e0jHStZlH-z8Gsoo1SBZJlG) | 35 video | 4 video/hafta |  [chat](https://discord.gg/7rX9TGQh)


## Sık Sorulan Sorular
#### Bilgisayar Bilimleri (Computer Science) eğitimi alarak hangi alanlarda çalışabilirim?
Bir Bilgisayar Bilimcisi olarak yazılım mühendisliği, kriptografi mühendisliği, sistem ve network mühendisliği, veritabanı mühendisliği vb. pek çok mühendislik alanında kariyerinizi devam ettirebilirsiniz. 
Bilgisayar Bilimlerinin teorik ayağını Hesaplama Kuramı, Algoritmalar ve Veri Yapıları, Bilişim ve Kodlama Kuramı, Programlama Dilleri gibi çalışma alanları oluştururken, uygulamalı tarafında Yapay Zeka, Bilgisayar Mimarisi ve Mühendisliği, Bilgisayar Grafikleri, Bilimsel Hesaplama, Bilgisayar Ağları, Paralel ve Dağıtık Sistemler, Bilgisayar Güvenliği ve Kriptografi ve Yazılım Mühendisliği gibi alanlar bulunmaktadır.

#### Neden Bilgisayar Bilimleri(Computer Science) eğitimi almalıyım?
Bilgisayar Bilimleri matematik'den köken almasıyla pek çok farklı disiplin ve alanla ilişkili bütün haline gelmiştir. Dolayısıyla Bilgisayar Bilimleri eğitimi almak kariyerinizde sadece programlama yapmakla kalmayıp bilgisayarın, programlamanın ve yazılımın arkasındaki tüm gelişimi ve disiplinleri anlayabilmenizi sağlar. 




devam edecek..
