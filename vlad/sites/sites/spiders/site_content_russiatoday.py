import scrapy, os

class NewsRussiaTodaySpider(scrapy.Spider):
    name = 'newsRussiaToday'
    rate = 5
    newsCounter=0
    pageCounter=0
    MaxPageNumber=30
    
    start_urls = [f'https://www.rt.com/search?category=&df=&dt=&format=&page={i}&pageSize=0&q=Ukraine&type=&xcategory=' for i in range(MaxPageNumber)]


    def __init__(self):

        self.download_delay = 1/float(self.rate)

    def parse(self, response):
        for link in response.css('div.list-card__content--summary   a::attr(href)').getall():
            yield response.follow(link, callback=self.parse_news)
            
    
    def parse_news(self,response):
        if(response.css('h1.article__heading::text').get()):
            self.newsCounter+=1
            
            filename = f'news{self.newsCounter}.txt'
            with open(os.path.dirname(__file__)+ "/RussiaToday/" + filename, 'w') as f:
                f.write(response.css('h1.article__heading::text').get().strip()+"\n\n")
                for el in response.xpath('//div[@class="article__text text "]/*[not(self::div)]//text()').getall():
                    f.write(el)


# scrapy crawl --set=ROBOTSTXT_OBEY='False' newsRussiaToday  