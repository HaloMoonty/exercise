#!/usr/bin/python
#coding:utf-8

import urllib2
import re
from bs4 import BeautifulSoup

def OpenPage(url):

    Myheaders = {}  
    req = urllib2.Request(url,headers=Myheaders)  
    f = urllib2.urlopen(req)
    data = f.read()  
    return data.decode("GBK",errors="ignore").encode("utf-8")

def ParseMainPage(page):

    soup = BeautifulSoup(page,"html.parser")
    GetList = soup.find_all(href=re.compile("read")) 
    UrlList = []
    for item in GetList:
        UrlList.append("http://www.shengxu6.com" + item["href"])   
    return UrlList

def ParseDetailPage(page):

    soup = BeautifulSoup(page,"html.parser")
    Title = soup.find_all(class_="panel-heading")[0].get_text()
    Content = soup.find_all(class_="content-body")[0].get_text()
    return Title,Content

def WriteDataToFile(data):
    with open("output.txt","a+") as f:
        f.write(data)

if __name__ == "__main__":
    url = raw_input("请输入要爬取的小说网址:")
    Main = OpenPage(url)
    UrlList = ParseMainPage(Main)
    print "Clone Begin..."
    for item in UrlList:
        print "Clone:" + item
    detail = OpenPage(item)
    Title,Content = ParseDetailPage(detail)
    data = "\n\n" + Title + "\n\n" + Content
    WriteDataToFile(data.encode("utf-8"))
    print "Clone done"

