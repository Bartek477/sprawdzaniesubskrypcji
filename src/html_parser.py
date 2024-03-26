from bs4 import BeautifulSoup

def parse_html(html_content):
    # Initialize a BeautifulSoup object with the provided HTML content
    soup = BeautifulSoup(html_content, 'html.parser')
    
    # Example of extracting data:
    # Let's assume we want to extract transaction details from a table or specific tags.
    # This example code would need to be adapted based on the actual structure of your HTML.
    
    transactions = []
    for transaction in soup.find_all('tr', class_='transaction'):
        date = transaction.find('td', class_='date').text
        description = transaction.find('td', class_='description').text
        amount = transaction.find('td', class_='amount').text
        transactions.append({
            'date': date.strip(),
            'description': description.strip(),
            'amount': amount.strip()
        })
    return transactions