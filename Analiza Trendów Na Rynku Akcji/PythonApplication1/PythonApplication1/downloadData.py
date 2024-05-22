import yfinance as yf
import pandas as pd
import webbrowser

def fetch_stock_data(ticker, start_date, end_date):
    
    #Pobiera dane dotyczace akcji o okreslonym symbolu (ticker)
    #z serwisu Yahoo Finance w podanym zakresie dat.
    
    stock_data = yf.download(ticker, start=start_date, end=end_date)
    return stock_data

