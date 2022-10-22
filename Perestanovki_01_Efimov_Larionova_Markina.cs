using System;
using System.Collections.Generic;
using System.Linq;

namespace Взаимная_рекурсия
{
    class Program
    {
        static List<string> list = new List<string>();
        static string Foo0(int k,string str)
        {
            
            if (k != 0)
            {
                str += "0";
                Foo1(k - 1, str);
            }
            else
            {
                list.Add(str);
            }
            return str;
        }

        static string Foo1(int k, string str)
        {
            
            if (k != 0)
            {
                str = str + "1";
                if (str.EndsWith("1"))
                {
                    Foo0(k - 1, str);
                    Foo1(k - 1, str);
                    return "";
                }
                else
                {
                    Foo1(k - 1, str);
                    return "";
                }

            }
            else
            {
                list.Add(str);
                return "";
            }
                
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Введите длину строк");
            int k = Convert.ToInt32(Console.ReadLine());
            string str = Foo0(k, "");
            str = Foo1(k, "");
            list = list.Distinct().ToList();
            foreach(var item in list)
                Console.WriteLine(item);
        }
    }
}
