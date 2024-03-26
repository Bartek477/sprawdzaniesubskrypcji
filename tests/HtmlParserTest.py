import unittest
from html_parser import parse_html

class HtmlParserTest(unittest.TestCase):
    def test_parse_html_basic(self):
        # Example HTML content. Replace this with the actual structure you expect.
        html_content = """
        <html>
        <body>
            <tr class='transaction'>
                <td class='date'>2024-03-01</td>
                <td class='description'>Coffee at Tim Hortons</td>
                <td class='amount'>$2.99</td>
            </tr>
            <tr class='transaction'>
                <td class='date'>2024-03-02</td>
                <td class='description'>Books from Amazon</td>
                <td class='amount'>$20.00</td>
            </tr>
        </body>
        </html>
        """
        expected = [
            {'date': '2024-03-01', 'description': 'Coffee at Tim Hortons', 'amount': '$2.99'},
            {'date': '2024-03-02', 'description': 'Books from Amazon', 'amount': '$20.00'}
        ]
        
        # Call the parse_html function and assert the expected outcome
        result = parse_html(html_content)
        self.assertEqual(expected, result)

if __name__ == '__main__':
    unittest.main()