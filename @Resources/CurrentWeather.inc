[Variables]
UpdateRate = 600
APIKey = 474c197bbde04b2b89ae38a936525b43
CityName = Montreal

CurrentWeatherURL = https://api.openweathermap.org/data/2.5/weather?q=#CityName#&appid=#APIKey#&units=metric&lang=fr


[@FullCurrentAPI]
Measure = WebParser
URL = #CurrentWeatherURL#
UpdateRate = 
RegExp = (?siU)^(.*)$
StringIndex = 1


; =========================================
; General Information information
; =========================================

[@GeneralInfoParent]
Measure = WebParser
URL = [@FullCurrentAPI]
StringIndex=1
RegExp = (?siU)"dt":(.*),

[@CurrentObservationTimeStamp]
Measure = WebParser
URL = [@GeneralInfoParent]
StringIndex = 1

;[@CurrentObservationConvertedTimeStamp]
;Measure = Time
;Timestamp = ([@CurrentObservationTimeStamp] + 11644472548 + [@LocationTimezone])
;DynamicVariables = 1


; =========================================
; Location information
; =========================================

[@LocationParent]
Measure = WebParser
URL = [@FullCurrentAPI]
StringIndex=1
RegExp = (?siU)"coord":.*"lon":(.*),.*"lat":(.*)},.*"timezone":(.*),.*"id":(.*),.*"name":.*"(.*)",.*"cod":(.*)}

[@LocationLongitude]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 1

[@LocationLatitude]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 2

[@LocationTimezone]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 3

[@LocationID]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 4

[@LocationName]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 5

[@LocationCode]
Measure = WebParser
URL = [@LocationParent]
StringIndex = 6


; =========================================
; Weather Information
; =========================================

[@TemperatureParent]
Measure = WebParser
URL = [@FullCurrentAPI]
StringIndex = 1
RegExp = (?siU)"weather":.*"id":(.*),.*"main":"(.*)",.*"description":"(.*)",.*"icon":"(.*)".*"main":.*"temp":(.*),.*"feels_like":(.*),.*"temp_min":(.*),.*"temp_max":(.*),.*"pressure":(.*),.*"humidity":(.*)}.*"wind":.*"speed":(.*),.*"deg":(.*)}

[@TemperatureID]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 1

[@TemperatureMain]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 2

[@TemperatureDescription]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 3

[@TemperatureIcon]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 4

[@TemperatureCurrent]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 5

[@TemperatureFeels]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 6

[@TemperatureMin]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 7

[@TemperatureMax]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 8

[@TemperaturePressure]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 9

[@TemperatureHumidity]
Measure = WebParser
URL = [@TemperatureParent]
StringIndex = 10

; =========================================
; Other Information
; =========================================

[@OtherWeatherParent]
Measure = WebParser
URL = [@FullCurrentAPI]
StringIndex = 1
RegExp = (?siU)"main".*"pressure":(.*),.*"humidity":(.*)}.*"wind".*"speed":(.*),.*"deg":(.*)}.*"clouds".*"all":(.*)}.*"sunrise":(.*),"sunset":(.*)}

[@WeatherPressure]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 1

[@WeatherHumidity]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 2

[@WeatherWindsSpeed]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 3

[@WeatherWindDirection]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 4

[@WeatherCloudCovrage]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 5

[@WeatherSunriseTimeStamp]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 6

[@WeatherSunsetTimeStamp]
Measure = WebParser
URL = [@OtherWeatherParent]
StringIndex = 7