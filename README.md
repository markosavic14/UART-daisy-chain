# UART-daisy-chain
ЛПРС 2 пројектни задатак\
\
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/PBzFP5aU4SA/0.jpg)](https://www.youtube.com/watch?v=PBzFP5aU4SA)

## Опис задатка
UART је асинхрони серијски протокол комуникације. Повезује се путем RX и TX сигнала.\
RX сигнал је серијски **улазни** сигнал за податке, а TX је серијски **излазни** сигнал за податке.\
Daisy-chain се реализује тако што се TX сигнал веже на RX другог у ланцу, TX другог у ланцу се веже на RX трећег у ланцу и тако даље до последњег чији се TX веже на RX првог.\
Конкретно у нашем систему са 3 уређаја у ланцу:\
![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/dijag_povez.png?raw=true)

## Реализација
Реализација UART daisy-chain-a на 3 Ардуино уређаја.\
Задатак **мастер** уређаја, првог у ланцу, јесте слање старт сигнала следећем у ланацу - **слејву**.\
На први слејв је везан PIR сензор. Када први слејв прими старт сигнал проверава стање PIR сензора и шаље вредност другом слејву.\
Други слејв, последњи у ланцу, је везан на GSM модул. На високу вредност примљеног сигнала шаље СМС поруку.\
![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/faraway.jpg?raw=true)


## Попис хардвера
| Компонента  | Слика |
| ------------- | ------------- |
| Ардуино Уно х3  | ![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/closeup.jpg?raw=true)  |
| Гсм модул SIM800L  | ![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/gsm.jpg?raw=true)  |
| ПИР сензор  | ![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/pir.jpg?raw=true)  |
| USB TO TTL YP-01  | ![alt text](https://github.com/markosavic14/UART-daisy-chain/blob/master/res/usb2uart.jpg?raw=true)  |













