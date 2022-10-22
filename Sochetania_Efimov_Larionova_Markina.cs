using System;
using System.Diagnostics;

namespace Адгосы
{
    class Program
    {
        public static int Check(int min, int max, string message = "")
        {
            Console.WriteLine(message);
            int num;
            bool isRead;
            do
            {
                isRead = int.TryParse(Console.ReadLine(), out num);
                if (!isRead)
                    Console.WriteLine("Error1!");
                else
                    if (num < min || num > max)
                {
                    Console.WriteLine("Введите число меньше n");
                    isRead = false;
                }
            } while (!isRead);
            return num;
        }
        static void Main(string[] args)
        {
            Stopwatch time1 = new Stopwatch();
            int k;
            int n;
            Console.Write("Введите n: ");
            n = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите k: ");
            k = Check(0,n);
            
            time1.Start();
            int p1 = P1(k, n);
            time1.Stop();
            long ts1 = time1.ElapsedTicks;
            Console.WriteLine($"1 метод     Ответ:{p1}, Время: {ts1}");

            time1.Restart();
            int p2 = P2(k, n);
            time1.Stop();
            long ts2 = time1.ElapsedTicks;
            Console.WriteLine($"2 метод     Ответ:{p2}, Время: {ts2}");
            
            Console.ReadKey();
        }
        static int P1(int k, int n)
        {
            if (k == n | k == 0)
                return 1;
            if (k != 1)
                return P1(k, n - 1) + P1(k - 1, n - 1);
            else
                return n;
        }
        static int P2(int k, int n)
        {
            if (k == 0|k==n)
                return 1;
            if (k != 1)
                return P2(k - 1, n - 1) * n / k;
            else
                return n;
        }
    }
}
