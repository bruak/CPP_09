# LIBFT

## WHAT A LOOK LİKE THE UNIT TEST


![ss](https://snipboard.io/BkIR72.jpg)
 
*note[]: ft_striteri artık bonus proje değildir.*

```C
unit test için[]:
* https://github.com/alelievr/libft-unit-test
```

## Functions

```C
int ft_isalpha(int str);
* girilen değerin harf olup olmadığını kontrol eder.

int ft_isdigit(int str);
* girilen değerin rakam olup olmadığını kontrol eder.

int ft_isalnum(int str)
* girilen değerin rakam ya da harf olup olmadığını(numerik) üstteki iki fonksiyonu kullanarak kontrol eder.

int ft_isascii(int c)
* ascii tablosundaki sayıların aralığında olup olmadığını kontrol eder.

int ft_isprint(int str)
* girilen değerin yazdırılabilir bir karakter olup olmadığını kontrol eder.

int ft_toupper(int c)
* a ile z arasındaysa harfleri büyütür.(her bir değer ascii''de sayı olduğu için int değeri döndürür ve int değeriyle işlem yapar.

int ft_tolower(int i) 
* aynısının tersi

int ft_strncmp(const char *s1, const char *s2, size_t n)
* gönderilen iki değeri istendiği inex kadar indexlerini kontrol eder, ASCİİ''de aynı değerde olanları geçer ve farklı olanların arasından farkı alır alınan farkı döndürür.
 //size_t : bu koddaki amacı indexlerin üzerinde işlem yapacağı için negatif değer olmaması gerekir.
 //const : bu koddaki amacı gönderilen değerlerin üzerinde işlem değiştirilmemesi sadece read-only olması
 //unsigned : bu koddaki amacı gönderilen değerin arasındaki farkın - olarak çıkmaması, (extanded ascii)

int	ft_memcmp(const void *s1, const void *s2, size_t n);
* gönderilen iki türü belli olmayan değeri alır kod içerisinde - dereğerlere inmemek için unsigned char değerine dönüştürür bu sayede void olarak fonksiyona giren değere char değeri üzerinden işlem yaparak byte değerlerine inebiliyor.

int ft_atoi(const char *str)
* karakterleri tamsayıya dönüştürür ilkten boşluk kontrolü yapar daha sonrasında değerin + veya - olup olmadığını kontrol eder. karakterleri teker teker alıp '0' ile çıkartarak dönüştürür.

void *ft_memset(void *s, int c, size_t n);
* bu fonskiyonda overflapping yaşabilme ihtimali var.
* void *s türünde bir değişken olduğu için ptr kullanarak bu değişkeni unsigned char değişkenine çevirilir
!* bu fonksiyonda int c yerine int yazılmasının sebebi bellekteki alanı 0 ila 255 arasında dolduracak kapasitede olmasıdır. unsingned char olarak da kullanılabilir.

void ft_bzero(void *s, size_t n);
* gönderilen alana istendiği kadar byte boyutunda NULL ile doldurur.

void *ft_memcpy(void *dst, const void *src, size_t n);
* null olup olmadığı test edilir, dst < src''den küçükse örtüşmeden dolayı ft_memcpy fonksiyonuna gönderilir.
* n değeri kadar geriye sayılarak str başlangıç adresi + n yerinden geri geri gelerek tüm değerler char değerinde kopyalanır.

void *ft_memchr(const void *s, int c, size_t n);
* girilen değerler arasında istenilen byte kadar ilerler ve girilen değer hedef değerde bulunursa 1 bulunmazsa 0 gönderir.

void *ft_calloc(size_t count, size_t size);
* isteneilen yer kadar alan ayırır ve bu alanı zeero ile doldurur

void ft_striteri(char *s, void (*f)(unsigned int, char *));
* karakter dizisini değiştirilmek istenirse doğrudan değiştirir.
* main fonksiyonunda str ile beraber farklı bir fonksiyon gönderilir gönderilen fonksiyonda index değeri de bulunur
* index değerini yazmak zorunludur


void ft_putchar_fd(char c, int fd);
* write operatörüyle fonksiyona gönderilen değerleri yazdırır.

void ft_putstr_fd(char *s, int fd);
* ft_putchar_fd ile arasındaki tek fark bu fonksiyonun ft_strlen fonksiyonunun kullarak tam bir diziyi yazdırır.

void ft_putendl_fd(char *s, int fd);
* yine dizi yazdırır fakat her harfte bir yeni satıra geçer.

void ft_putnbr_fd(int nb, int fd);
* putnbr fonksiyonundan sayıları byte byte yazdırır 

size_t ft_strlen(const char *str);
* gönderilen kodun index index sayısını gönderir, gönderirken de sizeof(char) değeri ile çarparak byte değerin sabitler bu yapılan işlem tüm sistemlerde düzgün çalışmasına yarar.

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
* istenilen uzunlık kadar dst değerine kopyalama işlemi yapar.

size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
* gönderilen iki dizeyi birleştirir. dest değerinde yeterli alan olduğu sürece. size -1 null iççim i < ise 0 dan başladığı için.

char *strchr(const char *str, int c);
* char * türünne dömüştürmesinin sebebi bir char döndüren fonksiyon olması ve farklı durumlarda derleyicilerle doğru çalışması.
*ft_strchr fonksiyonu, s karakter dizisi içindeki c karakterinin ilk geçtiği konumu bulur

char *ft_strrchr(const char *s, int c);
ft_strrchr fonksiyonu, s karakter dizisi içindeki c karakterinin son geçtiği konumu bulur

char *ft_substr(char const *s, unsigned int start, size_t len);
* fonksiyona bir dizi gönderir gönderdiği dizenin istediği indexten başlar ve başlanılan kısımdan sonraki indexler için ne kadar devam edileceği de len uzunluğunu kaydedilir.

char *ft_strnstr(const char *str, const char *needle, size_t len);
* dizinin başından başlayarak istenilen değeri arar ve bulduğu değeri adres olarak döndürür.
* strlen foknsiyonun döndürdüğü size_t değeri int değerine dönüştürülür.
*Örneğin, len parametresi 10 ve needle_len parametresi 3 olsun. Bu durumda, arama penceresi str dizisinin 0'dan 7'ye kadar olan karakterlerini tarayacaktır. Bu sayede, arama penceresi needle alt dizesini tam olarak içerebilecek boyutta olacaktır.

char *ft_strdup(const char *str);
* girilen str dizisini farklı bir parametre yaratarak malloc ile yer ayırır ve ayrılan yere str değerini kopyalar.

char *ft_strjoin(char const *s1, const char *s2);
* girilen iki dizenin uzunlukları kadar bir alan oluşturur bu alanı srtlcpy ve strlcat kullanarak tek bir dizede birleitirilir

char *ft_strtrim(char const *s1, char const *set);
* gönderilen string içindeki kaldırılması istenilen veriler kümesi örn( + - " " a b c) değerlerini yeni bir string olarak verir.
* sadece gönderilen stringin başından ve sonundan işlem yapabilir, ortasındaki değerleri değiştiremez
* farklı bir fonksiyona iki değeri de gönderir, ilk gönderilen değerin indexsinde aranacak olan değerler kümesini teker teker kontrol eder.

char **ft_split(char const *s, char c);
* istenilen değerleri gönderilen string içerisinde arar ve bulunan bu stringleri referans alarak görmezden gelerek yeni bir char* oluşturarak bu değerleri yeni birer char* dizilerine atar. bu dizileri de tek bir yerde tutar, tüm bu dizilere işaret eden değer ise şöyle gösterilir: **split. == *split[] = (a , b, c .....). 
* birinci pointer bir array dizisi tuttuğunu ikincisi ise birden fazla array olup en başındaki adresi char* şeklinde gösterdiğini gösterir.
* split içinde iki farklı fonksiyon bulunmaktadır, birinin görevi array içinde çıkarılmak istenilen değer referans alınarak kaç kelime olduğunu bulmak ve bu kadar alanda yer ayırmak. ikinci fonksiyonun görevi ise kelimeleri teker teker yeni ayrılan alanlara yerleştirmek.

!* ilk önce array alınr kelime kadar yer ayrılır ardından alınan array ayrılacak hedef karaktere göre kontrol edilir ve hangi kelimelerin hangi split[0,1,2] dizilerine yerleştireceği hedef karakterden index değeri çıkartılarak hangi indexte olduğu da bulunur, bulunan bu değerler yerlerine yeleştirilir.

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
* gönderilen str değerini aynı zamanda gönderilen fonskiyına while döngüsü içinde gönderir ve str değeri üzerinde işlem yapar bu işlemden önce de ft_malloc kullanarak alan ayırır.


``
