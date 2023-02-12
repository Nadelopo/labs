using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
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
    /// <summary>
    /// Логика взаимодействия для Cart.xaml
    /// </summary>
    /// 

    public partial class Cart : Page
    {
        readonly ObservableCollection<Item> gItems;
        public Cart(ObservableCollection<Item> items)
        {
            InitializeComponent();
            myListView.ItemsSource = items;
            gItems = items;
        }

        private void toProds(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new shop(gItems));
        }
    }
}
