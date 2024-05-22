#this Pyton script should be fed the *unlabeled* text file Comsol output for Electric fields
#from there it will turn it into a CSV readable for this program.
#the unlabeled CSV will have the same form, but be deliniated by commas instead of an uncertain number of spaces.
from pathlib import Path
import re #oh god
output = "ACEField.csv"
pathin = Path(__file__) / "../Fielddata/txt/AC E field Unlabeled" #replace this last bit with the relevant file for usage.
pathout = Path(__file__) / "../Fielddata/csv/" + output
with pathin.open() as infile:
    lines = infile.readlines
    for i in lines:
        re.sub(' +', ',', i)
        with pathout.open as outfile:
            outfile.write(i)