using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading;
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
    /// Логика взаимодействия для login.xaml
    /// </summary>
    public partial class login : Page
    {
        public login()
        {
            InitializeComponent();
        }

        private async void Button_Click(object sender, RoutedEventArgs e)
        {
            bool checkPass = Password.Password == "";
            bool checkLog = Login.Text == "";
          
            bool validate = !checkLog && !checkPass;

            if (!validate)
            {
                alert.Content = "заполните форму";
                await Task.Delay(2000);
                alert.Content = "";
            } else {
                ObservableCollection<Item> items = new ObservableCollection<Item> { };
                NavigationService.Navigate(new shop(items));
            }
        }
    }
}
