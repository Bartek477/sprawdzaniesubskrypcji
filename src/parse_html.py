# parse_html.py
from bs4 import BeautifulSoup

def parse_html(html_content):
    soup = BeautifulSoup(html_content, "html.parser")
    # Example: Find all links in the HTML content
    links = soup.find_all('a')
    return [link.get('href') for link in links]