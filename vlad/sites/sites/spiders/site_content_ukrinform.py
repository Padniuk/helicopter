import scrapy, os

class NewsUkrinformSpider(scrapy.Spider):
    name = 'newsUkrinform'
    rate = 5
    newsCounter=0
    pageCounter=0
    MaxPageNumber=30
    
    start_urls = [f'https://www.ukrinform.net/rubric-ato?page={i}' for i in range(MaxPageNumber)]


    def __init__(self):
        self.download_delay = 1/float(self.rate)

    def parse(self, response):
        for link in response.css('div.infinite-scroll a::attr(href)'):
            yield response.follow(link, callback=self.parse_news)
            
    
    def parse_news(self,response):
        if(response.css('div.newsHeading::text').get()):
            self.newsCounter+=1
            
            filename = f'news{self.newsCounter}.txt'
            with open(os.path.dirname(__file__)+ "/Ukrinform/" + filename, 'w') as f:
                f.write(response.css('div.newsHeading::text').get()+"\n\n")
                for el in response.css('div.newsText p::text'):
                    f.write(el.get()+" ")