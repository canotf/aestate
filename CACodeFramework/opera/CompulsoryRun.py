from CACodeFramework.exception import e_fields
from CACodeFramework.util.Log import CACodeLog


class Compulsory(object):
    @staticmethod
    def run_function(cls_func, args, kwargs):
        """
        强制执行
        """
        try:
            return cls_func(*args, **kwargs)
        except TypeError as e:
            pass

        try:
            return cls_func(*args)
        except TypeError as e:
            pass

        try:
            return cls_func(**kwargs)
        except TypeError as e:
            pass

        try:
            return cls_func()
        except TypeError as e:
            pass

    @staticmethod
    def search_target(module, target_names):

        """
        深度搜素树
        """

        if len(target_names) == 0:
            return module
        # 当前的标记位置
        now_target = target_names[0]
        del target_names[0]
        if hasattr(module, now_target):
            next_module = getattr(module, now_target)
            return Compulsory.search_target(next_module, target_names)
        else:
            CACodeLog.err(ImportError,
                          e_fields.CACode_Factory_Error(
                              f'The package name does not exist in the search tree: {now_target}, please check ' +
                              'whether the package name is filled in correctly'))
