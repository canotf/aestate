from testOpera.table.demoModels import Demo

demo = Demo()
r1 = demo.create(Demo(name="test", password="test"))
demo.name = "test"
demo.password = "test"
r2 = demo.save()
data = {
    'name': 'test',
    'password': 'test'
}
r3 = demo.copy(**data).save()
a = demo.execute_sql("INSERT INTO `_demo`.`demo` ( `name`, `password`, `create_time`, `update_time`) "
                     "VALUES ( 'asdasd', 'aaa', '2021-05-28 00:08:22', '2021-07-24 02:40:38')")
print("r1", r1)
print("r2", r2)
print("r3", r3)
print('r4', a)
