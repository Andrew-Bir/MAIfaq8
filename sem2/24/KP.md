<!DOCTYPE html><html><head><meta charset="utf-8"><title>Untitled Document.md</title><script type="text/javascript">
//<![CDATA[
window.__cfRocketOptions = {byc:0,p:0,petok:"d44e082a1cb2524ec842d2cd055fa719b991d1bf-1515452522-1800"};
//]]>
</script>
<script type="text/javascript" src="https://ajax.cloudflare.com/cdn-cgi/scripts/9014afdb/cloudflare-static/rocket.min.js"></script>
<style></style></head><body id="preview">
<h1><a id="____0"></a>Отчет по курсовому проекту</h1>
<h2><a id="____1"></a>по курсу “Логическое программирование”</h2>
<h3><a id="____3"></a>студентка: Пашкевич А. Р.</h3>
<h2><a id="__5"></a>Результат проверки</h2>
<table class="table table-striped table-bordered">
<thead>
<tr>
<th>Преподаватель</th>
<th>Дата</th>
<th>Оценка</th>
</tr>
</thead>
<tbody>
<tr>
<td>Сошников Д.В.</td>
<td></td>
<td></td>
</tr>
<tr>
<td>Левинская М.А.</td>
<td></td>
<td></td>
</tr>
</tbody>
</table>
<blockquote>
<p><em>Комментарии проверяющих (обратите внимание, что более подробные комментарии возможны непосредственно в репозитории по тексту программы)</em></p>
</blockquote>
<h2><a id="_14"></a>Введение</h2>
<p>Выполняя данный курсовой проект, я получил важные знания и навыки . При написании эссэ по теме: “Различия алгоритмов поиска в императивных и логических языках программирования” я стал углубил свои знания в различии разных методов программирования и сделал для себя существенные выводы. Также узнал об особенностях обработке текстовых файлов формата GEDCOM, написав парсер для данного типа файлов. Мной были закреплены навыки, полученные в 3 лабораторной работе, связанные с поиском в пространстве решений.</p>
<h2><a id="_18"></a>Задание</h2>
<p>вариант 1<br>
использовать предикат:<br>
child(ребенок, родитель)<br>
male(человек)<br>
female(человек)</p>
<ol start="3">
<li>
<p>Реализовать предикат проверки|поиска следующих родственников:<br>
вариант 5 - Свекровь</p>
</li>
<li>
<p>Реализовать программу на языке Prolog, которая позволит определять<br>
степень родства двух произвольных индивидуумов в дереве</p>
</li>
<li>
<p>Реализовать естественно-языковый интерфейс к системе,<br>
позволяющий задавать вопросы относительно степеней родства,<br>
и получать осмысленные ответы. Допускается использовать английский<br>
язык в качестве базового.</p>
</li>
</ol>
<h2><a id="___37"></a>Получение родословного дерева</h2>
<p>В интернете мной было найдено родословное дерево семейство Тюдоров</p>
<h2><a id="___41"></a>Конвертация родословного дерева</h2>
<h2><a id="___44"></a>Предикат поиска родственника</h2>
<p>В предоставленном мне варианте задания необходимо было используя предикаты child, male и female реализовать предикат поиска свекрови для любого члена семьи реализация представлена следующим образом</p>
<p>mother_in_law(F1,F2):-<br>
filiation(wife, F2, M),<br>
filiation(mother, F1, M),<br>
F1 = F2.</p>
<p>Результат работы:</p>
<h2><a id="___56"></a>Определение степени родства</h2>
<p>Для определения степени родства целесообразно использовать поиск в ширину, чтобы найти кратчайшее отношение родства.???</p>
<p>Результат работы</p>
<h2><a id="_67"></a>Выводы</h2>
<p>Язык программирования Prolog является отличным инструментом для решения такого типа задачи, поскольку поиск ответа на запрос выполняется прологом автоматически, можно сфокусировать внимания на описание предикатов, описывающие отношение, по которому следует искать ответ, нежели как это принято в императивных языках программирования реализовывать сложный алгоритм поиска, учитывая всевозможные случаи.</p>

</body></html>