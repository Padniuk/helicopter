import scrapy, os

class EuroNewsSpider(scrapy.Spider):
    name = 'EuroNews'
    rate = 5
    newsCounter=0
    pageCounter=0
    MaxPageNumber=200
    
    start_urls = [f'https://www.euronews.com/tag/russia-ukraine-invasion?p={i}' for i in range(MaxPageNumber)]


    def __init__(self):
        self.download_delay = 1/float(self.rate)

    def parse(self, response):
        for link in response.css('div.m-object__body a::attr(href)'):
            yield response.follow(link, callback=self.parse_news)
            
    
    def parse_news(self,response):
        if(response.xpath('//h1[@class="c-article-title u-display-inline u-text-align--start"]/text()').get().strip()):
            self.newsCounter+=1
            
            filename = f'news{self.newsCounter}.txt'
            with open(os.path.dirname(__file__)+ "/EuroNews/" + filename, 'w') as f:
                f.write(response.xpath('//h1[@class="c-article-title u-display-inline u-text-align--start"]/text()').get().strip()+"\n\n")
                for el in response.xpath('//div[@class="c-article-content js-article-content "]//text()').getall():
                    f.write(el.replace(u'\xa0', u' '))