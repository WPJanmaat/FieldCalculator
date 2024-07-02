#this Pyton script should be fed the *unlabeled* text file Comsol output (spreadsheet form)
#from there it will turn it into a CSV readable for this program.
#the unlabeled CSV will have the same form, but be deliniated by commas instead of an uncertain number of spaces.
from pathlib import Path
import re #oh god
outpath = "../../Fielddata/csv"
output = "../../Fielddata/csv/SimTestDCField.csv" #output file name
pathin = Path(__file__) / "../../Fielddata/txt/DC E Field from test trap Unlabeled.txt" #replace this last bit with the relevant file for usage.
pathout = Path(__file__) / output
dirpath = Path(__file__) / outpath
dirpath.mkdir(parents=True, exist_ok=True)
with pathin.open() as infile:
    with pathout.open("w", encoding ="utf-8") as outfile:
        for line in infile:
            outline = re.sub(' +', ',', line)
            outline = re.sub('NaN', '0', outline)
            outfile.write(outline)