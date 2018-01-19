using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using game_data;

namespace csharptest
{
    class Program
    {
        static void Main(string[] args)
        {

            if (TableConfig.Instance.LoadTableConfig()) {
                td_test_item item = td_test.Instance.GetTableItem(1);
                item.role_id += 1;
            }
        }
    }
}
