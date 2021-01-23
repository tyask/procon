#!/usr/bin/env python3

import sys
import time
import requests
from bs4 import BeautifulSoup
from requests_html import HTMLSession

home='https://atcoder.jp'
url = home + '/ranking?page={}'
page=1
session = requests.Session()

def err(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

def download_user_href():
    user_href=[]
    for i in range(1, page+1):
        up = url.format(i)
        err('downloading usernames from {}.'.format(up))
        r = session.get(up)
        soup = BeautifulSoup(r.content, 'html.parser')
        for e in soup.find_all('a', class_='username'):
            user_href.append(e['href'])
        time.sleep(1)
    return user_href

def download_user_records(user_href):
    username = u.split('/')[2]
    err('downloading user record: {}', username)

    user_href = user_href[:1]
    url = home + u + '/history'
    r = session.get(url)
    soup = BeautifulSoup(r.content, 'html.parser')
    table = soup.find("table", id='history')
    rows  = table.find_all('tr')
    for row in rows:
        record = [username]
        for c in row.find_all('td')[:6]:
            record.append(c.contents[0].string)
        records.append(record)
    return records

def download_users_records(user_hrefs):
    records = []
    for u in user_hrefs:
        records.extend(download_user_records(u))
        time.sleep(1)
    return records

def main():
    user_hrefs = download_user_href()
    recoreds   = download_users_records(user_hrefs)
    for r in recoreds:
        print(','.join(r))

main()

#site = requests.get(url)
#data = BeautifulSoup(site.text, 'html.parser')
#print(data.title)
#print(data.title.text)
#print(data.find(id='pre-sample1'))
#print(data.prettify());
