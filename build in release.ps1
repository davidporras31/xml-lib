echo "##########################-start-##########################";


cp .\site\docs\base.html .\site\docs\example\load.html
cp .\site\docs\base.html .\site\docs\example\save.html
cp .\site\docs\base.html .\site\docs\example\make.html
cp .\site\docs\base.html .\site\docs\example\Search.html

cp .\site\docs\base.html .\site\docs\XMLBase\XMLBase.html
cp .\site\docs\base.html .\site\docs\XMLBase\load_xml_file.html
cp .\site\docs\base.html .\site\docs\XMLBase\save_xml_file.html

cp .\site\docs\base.html .\site\docs\XMLRoot\XMLRoot.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_element.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_element.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_text.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_text.html
cp .\site\docs\base.html .\site\docs\XMLRoot\length_text.html
cp .\site\docs\base.html .\site\docs\XMLRoot\length_text_without_wihtespace.html
cp .\site\docs\base.html .\site\docs\XMLRoot\add_attribut.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_attribut.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_attribut.html
cp .\site\docs\base.html .\site\docs\XMLRoot\length_attribut.html
cp .\site\docs\base.html .\site\docs\XMLRoot\add_value.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_value.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_value.html
cp .\site\docs\base.html .\site\docs\XMLRoot\length_value.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_parent.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_parent.html
cp .\site\docs\base.html .\site\docs\XMLRoot\add_child.html
cp .\site\docs\base.html .\site\docs\XMLRoot\set_child.html
cp .\site\docs\base.html .\site\docs\XMLRoot\get_child.html
cp .\site\docs\base.html .\site\docs\XMLRoot\length_child.html

cp .\site\docs\base.html .\site\docs\XMLUtility\Search_by_atribut.html
cp .\site\docs\base.html .\site\docs\XMLUtility\Search_by_element.html

./replace_core.ps1 -one_file $True -folder "./site/docs/example/load.html" -result "./site/docs/example/" -rule "/base/article/@/load/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/example/save.html" -result "./site/docs/example/" -rule "/base/article/@/save/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/example/make.html" -result "./site/docs/example/" -rule "/base/article/@/make/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/example/Search.html" -result "./site/docs/example/" -rule "/base/article/@/Search/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLBase/XMLBase.html" -result "./site/docs/XMLBase/" -rule "/base/article/@/XMLBase/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLBase/load_xml_file.html" -result "./site/docs/XMLBase/" -rule "/base/article/@/load_xml_file/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLBase/save_xml_file.html" -result "./site/docs/XMLBase/" -rule "/base/article/@/save_xml_file/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/XMLRoot.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/XMLRoot/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_element.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_element/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_element.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_element/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_text.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_text/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_text.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_text/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/length_text.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/length_text/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/length_text_without_wihtespace.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/length_text_without_wihtespace/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/add_attribut.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/add_attribut/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_attribut.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_attribut/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_attribut.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_attribut/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/length_attribut.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/length_attribut/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/add_value.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/add_value/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_value.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_value/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_value.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_value/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/length_value.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/length_value/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_parent.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_parent/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_parent.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_parent/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/add_child.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/add_child/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/set_child.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/set_child/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/get_child.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/get_child/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLRoot/length_child.html" -result "./site/docs/XMLRoot/" -rule "/base/article/@/length_child/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLUtility/Search_by_atribut.html" -result "./site/docs/XMLUtility/" -rule "/base/article/@/Search_by_atribut/article/"
./replace_core.ps1 -one_file $True -folder "./site/docs/XMLUtility/Search_by_element.html" -result "./site/docs/XMLUtility/" -rule "/base/article/@/Search_by_element/article/"

./replace_core.exe /folder site/ /filter rules.txt
./replace_core.exe /folder site/docs/ /filter rules.txt
cp .\site\docs\main.js .\bin\site\docs\main.js
./replace_core.exe /folder site/docs/img/ /filter rules.txt
cp .\site\docs\img\logo.png .\bin\site\docs\img\logo.png
./replace_core.exe /folder site/docs/example/ /filter rules.txt
./replace_core.exe /folder site/docs/XMLBase/ /filter rules.txt
./replace_core.exe /folder site/docs/XMLRoot/ /filter rules.txt
./replace_core.exe /folder site/docs/XMLUtility/ /filter rules.txt

mkdir .\site\docs\styles
cp  .\site\docs\styles\vs2015.css .\bin\site\docs\styles\vs2015.css
rm .\bin\site\docs\base.html

echo "##########################-fin-##########################";