from parser import myparser
from parser import myparser_rule

parser = myparser.MyParser()
parser.add_rules(open('syntax.md', 'r').readlines())

nodes = set()
links = set()

for rule in parser.rule_list:
    nodes.add(rule.name)

    if type(rule) in {myparser_rule.RuleList, myparser_rule.RuleBuiltin}:
        for line in rule.rule:
            for item in line:
                if type(item[1]) is myparser_rule.RuleItemRef:
                    links.add((rule.name, item[1].target))

with open('syntax.html', 'w') as ht_file:
    ht_file.write('''<!DOCTYPE html>
<meta charset="utf-8">
<style>

.link {
    stroke: #ccc;
}

.node text {
    pointer-events: none;
    font: 10px sans-serif;
}

</style>
<body>
<script src="d3.v3.min.js"></script>
<script>

var width = 960,
    height = 640,
    border = 40;

var fill = d3.scale.category20();

var svg = d3.select("body").append("svg")
    .attr("width", width)
    .attr("height", height);

var force = d3.layout.force()
    .gravity(.02)
    .friction(.5)
    .distance(80)
    .charge(-200)
    .size([width, height]);

var nodes = [
''')

    nodes = list(nodes)

    for item in nodes:
        ht_file.write('    {"name": "' + item + '"},\n')

    ht_file.write('''];

var links = [
''')

    for item in links:
        ht_file.write(
            '    {"source": ' + str(nodes.index(item[0]))
            + ', "target": ' + str(nodes.index(item[1]))
            + '},\n'
        )

    ht_file.write('''];

force
    .nodes(nodes)
    .links(links)
    .start();

var link = svg.selectAll(".link")
    .data(links)
    .enter().append("line")
    .attr("class", "link");

var node = svg.selectAll(".node")
    .data(nodes)
    .enter().append("g")
    .attr("class", "node")
    .call(force.drag);

node.append("svg:circle")
    .attr("r", 5)
    .style("fill", function(d) { return fill(0); })
    .style("stroke", function(d) { return d3.rgb(fill(0)).darker(); })
    .style("stroke-width", "1.5px")
    .call(force.drag);

node.append("text")
    .attr("dx", 12)
    .attr("dy", ".35em")
    .text(function(d) { return d.name });

force.on("tick", function() {
    node.attr("cx", function(d) {
        return d.x = Math.max(border, Math.min(width - border, d.x));
    });

    node.attr("cy", function(d) {
        return d.y = Math.max(border, Math.min(height - border, d.y));
    });

    node.attr("transform", function(d) {
        return "translate(" + d.x + "," + d.y + ")";
    });

    link.attr("x1", function(d) { return d.source.x; })
        .attr("y1", function(d) { return d.source.y; })
        .attr("x2", function(d) { return d.target.x; })
        .attr("y2", function(d) { return d.target.y; });
});
</script>
</body>
''')
