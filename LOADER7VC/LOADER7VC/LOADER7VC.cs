using System;
using System.Diagnostics;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        string EXEInput;

        // Check if there is a command line argument
        if (args.Length > 0)
        {
            // Use the provided command line argument as the file path
            EXEInput = args[0];
        }
        else
        {
            // Check if LOADER7.EXE or Dev7VM.EXE exists in the current directory
            string loader7Path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "LOADER7.EXE");
            string dev7VMPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Dev7VM.EXE");

            if (File.Exists(loader7Path))
            {
                EXEInput = loader7Path;
            }
            else if (File.Exists(dev7VMPath))
            {
                EXEInput = dev7VMPath;
            }
            else
            {
                Console.WriteLine("LOADER7.EXE or Dev7VM.EXE not found in the current directory.");
                return;
            }
        }

        // Continue with the rest of the code...
        FileVersionInfo myFileVersionInfo = FileVersionInfo.GetVersionInfo(EXEInput);

        Console.WriteLine("\nGeneral Infos: \n");
        Console.WriteLine("Original Filename: " + myFileVersionInfo.OriginalFilename);
        Console.WriteLine("Description: " + myFileVersionInfo.FileDescription);
        Console.WriteLine("Version: " + myFileVersionInfo.FileVersion);
        Console.WriteLine("Productname: " + myFileVersionInfo.ProductName);
        Console.WriteLine("Internalname: " + myFileVersionInfo.InternalName);
        Console.WriteLine("Copyright: " + myFileVersionInfo.LegalCopyright);

        Console.WriteLine("\b");
        Console.WriteLine("Thanks for using LOADER7VC!");

        Console.WriteLine("\nPress any key to exit LOADER7VC");
        Console.ReadKey();
    }
}
