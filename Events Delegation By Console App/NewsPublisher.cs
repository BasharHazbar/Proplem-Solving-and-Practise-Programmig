using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegation_By_Console_App
{

    public class NewsArtical
    {
        public string Title { get; }
        public string Content { get; }

        public NewsArtical(string Title, string Content)
        {
            this.Title = Title;
            this.Content = Content;
        }
    }

    public class NewsPublisher
    {
        public EventHandler<NewsArtical> NewNewsPuplished;

        public void PublishNews(string Title, string Content)
        {
            NewNewsPuplished?.Invoke(this,new NewsArtical(Title, Content));
        }
    }

    public class NewsSubscriber
    {

        public string Name { get; }

        public NewsSubscriber(string Name)
        {
            this.Name = Name;
        }
        public void Subscribe(NewsPublisher NewsPublisher)
        {
            NewsPublisher.NewNewsPuplished += HandleNewNewsPuplished;
        }

        public void UnSubscribe(NewsPublisher NewsPublisher)
        {
            NewsPublisher.NewNewsPuplished -= HandleNewNewsPuplished;
        }
        public void HandleNewNewsPuplished(object sender, NewsArtical Artical)
        {
            Console.WriteLine($"{Name} Recieved New News Artical:- ");
            Console.WriteLine($"The Title : {Artical.Title}");
            Console.WriteLine($"The Artical: {Artical.Content} C");

            Console.WriteLine();
        }
    }
}
