#	Update

1.	These two scripts simple show the weather today & tomorrow in SH. Weather info via [Weather China](http://www.weather.com.cn/weather/101020100.shtml)

2.	BeautifulSoup is used as the html parser for `get_weather_with_bs4.py`. So the module bs4 need to be installed when running this script:

	```bash
	$ python3 get_weather_with_bs4.py
	```

3.	There is another way to get the weather using builtin module `re`. Just run the following command:

	```bash
	$ python3 get_weather_with_re.py
	```

Note that if it's too late in the night, today's weather(or more exactly, tonight's weather) will not be displayed in the `get_weather_with_re.py`, unless you uncomment the commented code.

#	Out of date

Below is the original readme, whose api is no longer usable.

1. This script simply shows the weather today & tomorrow in SH. Weather info via [weathercn](m.weathercn.com)



