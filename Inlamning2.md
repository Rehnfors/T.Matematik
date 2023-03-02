

# Inlämning 2 - Smartwatch
## Jesper Rehnfors
### Mars 2023
---


I den här inlämningen tilldelades vi uppgiften att göra en case study på ett system.  
Uppgiften gick ut på att välja ut ett par funktioner ur det valda systemet, och matematiskt bevisa hur de fungerar. 3 av lösningarna ska dessutom ha programmeringslösningar.  
Jag har valt att göra en case study på en smart watch. Dels för att jag äger en, men också för att det föll mest naturligt.  

## Pulsmätning


Smartklockan använder sig av en PPG-sensor (Photoplethysmogram) för att läsa av ett hjärtas rytm. En PPG-sensor består av en eller flera LED-dioder samt en fotodiod.
LED-dioderna ger ifrån sig ett ljus med våglängden 530 Nanometer (nm, grönt), då denna våglängd når ner till artärerna och inte längre än så. Tidigare var det vanligt att man använde våglängden 640nm (rött), men detta var inte riktigt lika pricksäkert.
När blod flödar I artärerna transporterar det bort en del av det gröna ljuset. Fotodioden är aktiv och känner av hur mycket som reflekteras tillbaka. Fotodioden skapar elektronisk spänning av fotoner, och skickar spänningen 0-5V till chipets analogue-digital converter (ADC).
Chipets ADC antar att 5V = 1023 (10 bitar, 1111111111b) och 0V = 0b.  


$$\frac{1023}{5} = \frac{ADC\,värde}{spänning}$$
**Till exempel:**

$$2,4V\cdot\frac{1023}{5V} = 491 = 0111101011b$$

<br>  
Fortsättning följer i programmeringslösningen "ppgsensor.cpp", där vi använder bitshift << 10 och bitshift OR för att så slamman detta värde med ett annat, för att räkna ut antal bpm.

---
<br>
  
## Mäta distans med gps  

En smartklocka använder GPS för att mäta distans på löppass eller promenader.
GPS:en levererar en x-koordinat (latitud), en y-koordinat (longitud).
Avståndet mellan punkterna kan beräknas enligt avståndsformeln:

$$ d = \sqrt{(x1-x0)² + (y1-y0)²} $$

**Till exempel:**  

$x_0 = 59,746846 N$
$y_0 = 18.896561 E$

$x_1 = 59.748037 N$
$y_1 = 18,897966 E$  

<br>  

$$ d = \sqrt{(59.748037² – 59.746846²) + (18.897966² – 18.896561²)}$$ 
$$d = 0.442063 grader$$  

**För att översätta från grader till meter:**  

$$0.442063\,grader * 111,320\,meter = 49.21\,meter$$
$$111,320\,meter = 1\,grad\,vid\,ekvatorn$$
<br>
GPS:en kan också leverera en tidpunkt vid samma tillfälle då den levererar koordinater.
Med hjälp av detta kan man beräkna personens hastighet mellan punkterna.

$$T = t_1-t_0$$
$$T = (18:34.30 – 18:32.07)$$
$$T =  2min, 23s$$

**För att beräkna hastigheten:**  

$$2min*60s = 120s + 23s$$
$$49,21m / 143 s = 0,344m/s$$

**Klockan visar hastighet i km/h.**

$$(3600 s) / (1000m) = 3,6$$
$$hastigheten = 0,344\,m/s \cdot 3,6 = 1,2384 km/h$$

Om distansen inte är ett rakt streck, kan flera distanser adderas för att utgöra en runda.  

programmeringslösning i "distance.cpp".

---
## Strömförsörjning

Batteriet har en kapacitet på 300mAh.  
För att beräkna hur länge det räcker kan vi dividera batteriets kapacitet med den genomsnittliga energiförbrukningen.

$$Batteritid = \frac{kapacitet(mAh)}{genomsnittlig\,förbrukning(mWh)}$$

Om vi mäter spänningen på ett fulladdat batteri kan vi se att spänningen är 3.7V.  

$$Batteriets\,kapacacitet\,i\,Wh = (300mAh\cdot 3.7V)/1000 = 1.11Wh$$  
Efter några timmars användning vill man kunna se hur mycket batteri klockan har kvar.  
En ny spänningsmätning visar 3.2V.
$$\frac{300mAh \cdot 3.2V}{1000} = 0.96 Wh$$

$$\frac{0.96Wh}{1.11Wh} = 0,8649$$
Ca 86% av batteriets laddning återstår.

programmeringslösning i "batterypercentage.cpp"
