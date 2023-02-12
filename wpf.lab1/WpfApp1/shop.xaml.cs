using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using static WpfApp1.shop;

namespace WpfApp1
{
    
    public partial class shop : Page
    {

        public class Item
        {
            public int id;
            public string title { get; set; }
            public int price { get; set; }
            public int count { get; set; }
        }

        ObservableCollection<Item> CartItems = new ObservableCollection<Item> {
        new Item { id = 0, title = "i5 - 11400 f", price = 11500, count = 1},
            new Item { id = 1, title = "i5 - 12400 f", price = 14500, count = 1 },
            new Item { id = 2, title = "i5 - 12600 kf", price = 21500, count = 1 },
            new Item { id = 3, title = "i7 - 12700 kf", price = 30500, count = 1 },
            new Item { id = 4, title = "i7 - 13700 kf", price = 36500, count = 1 }};

        public shop(ObservableCollection<Item> newItems)
        {
            InitializeComponent();
            
            myListView.ItemsSource = CartItems;
            CartItems = newItems;
        }

        private void Buy(object sender, RoutedEventArgs e)
        {
            var btnn = sender as Button;
            if (btnn == null) return;
            var item = btnn.DataContext as Item;

            if(!CartItems.Any(x => x.id == item.id))
            {
                CartItems.Add(item);
            } else
            {
                foreach (var itemm in CartItems.Where(x => x.id  == item.id))
                {
                    itemm.count++;
                }
            }
            lb.Content = item.count;
        }


        private void toCart(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Cart(CartItems));
        }

        private void toProds(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new shop(CartItems));
        }
    }
}
