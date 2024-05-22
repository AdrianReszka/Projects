import yfinance as yf
import pandas as pd
import webbrowser

from downloadData import fetch_stock_data
from plots import plot_trends
from addColumns import StochRSI, add_moving_average

# Ustawienia
ticker = 'AAPL'  # Przykladowy symbol akcji (Apple Inc.)
start_date = '2022-01-01'
end_date = '2023-01-01'


# Pobierz dane dotyczace akcji
stock_data = fetch_stock_data(ticker, start_date, end_date)

# Dane calego NASDAQ

nasdaq_data = fetch_stock_data('^IXIC', start_date, end_date)

# Dodanie sredniej kroczaca
stock_data = add_moving_average(stock_data)

stock_data = StochRSI(stock_data)

# Wyswietlenie wykresow trendow
plot_trends(stock_data, nasdaq_data, ticker)

#Strona Yahoo Finance dla wybranego symbolu akcji
#yahoo_finance_url = f'https://finance.yahoo.com/quote/{ticker}'
#webbrowser.open_new_tab(yahoo_finance_url)

# Dodajemy podglad danych
#print(stock_data.head())
#print()
#print('\n')
#print(stock_data.tail())